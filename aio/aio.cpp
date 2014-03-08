// g++ test.cpp -lrt -laio

#include <stdlib.h>
#include <stdio.h>
#include <libaio.h>
#include <stdint.h>
#define __STDC_FORMAT_MACROS 1
#include <inttypes.h>
#include <sys/select.h>
#include <sys/eventfd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include <algorithm>

const int total_jobs = 50000;
iocb jobs[total_jobs];
int cursor = 0; // the next job to be submitted
int num_completed = 0; // the number of completed jobs
int in_progress = 0; // number of outstanding jobs

const int buffer_size = 0x4000;
char* buffer = 0;

uint64_t time_now()
{
	struct timespec tv;
	int ret = clock_gettime(CLOCK_MONOTONIC, &tv);
	if (ret != 0) {
		perror("clock_gettime");
		exit(1);
	}
	return uint64_t(tv.tv_sec) * 1000000000 + tv.tv_nsec;
}

int main(int argc, const char* argv[])
{
	if (argc != 2) {
		fprintf(stderr, "usage: iosubmit_test <file>\n");
		return 1;
	}

	buffer = (char*)valloc(buffer_size);
	if (buffer == 0) {
		fprintf(stderr, "no memory\n");
		return 1;
	}

	io_context_t queue = 0;
	int ret = io_setup(512, &queue);
	if (ret != 0) {
		fprintf(stderr, "io_setup: %s\n", strerror(ret));
		return 1;
	}

	int event = eventfd(0, 0);
	if (ret < 0) {
		perror("eventfd");
		return 1;
	}

	int file = open(argv[1], O_WRONLY | O_CREAT | O_DIRECT, 0755);
	if (file < 0) {
		perror("open");
		return 1;
	}
	
	memset(jobs, 0, sizeof(jobs));
	for (int i = 0; i < total_jobs; ++i) {
		iocb& j = jobs[i];
		
		j.u.c.buf = buffer;
		j.u.c.nbytes = buffer_size;
		j.u.c.offset = buffer_size * i;
		j.aio_fildes = file;
		j.aio_reqprio = 0;
		j.aio_lio_opcode = IO_CMD_PWRITE;
		io_set_eventfd(&j, event);
	}

	std::random_shuffle(&jobs[0], &jobs[total_jobs]);

	uint64_t start_time = time_now();
	printf("0\t%d\t%d\n", cursor, num_completed);

	while (num_completed < total_jobs) {
		const int submit_batch_size = 512;
		iocb* to_submit[submit_batch_size];
		int submitted = 0;
		do {
			int num_to_submit = (std::min)(submit_batch_size, total_jobs - cursor);
			for (int i = 0; i < num_to_submit; ++i) to_submit[i] = &jobs[cursor + i];
			submitted = io_submit(queue, num_to_submit, to_submit);
			if (submitted < 0) {
				fprintf(stderr, "io_submit: %s\n", strerror(errno));
			} else {
				cursor += submitted;
			}

			printf("%"PRId64"\t%d\t%d\n", time_now() - start_time, cursor, num_completed);
		} while (submitted == submit_batch_size);

		retry:
		fd_set set;
		FD_ZERO(&set);
		FD_SET(event, &set);
		ret = select(event + 1, &set, 0, 0, 0);
		if (ret < 0 && errno == EINTR) goto retry;
		if (ret < 0) {
			perror("select");
			return 1;
		}

		if (FD_ISSET(event, &set))
		{
			const int max_events = 300;
			io_event events[max_events];
			int64_t n = 0;
			ret = read(event, &n, sizeof(n));
			if (ret != sizeof(int64_t)) {
				perror("read(eventfd)");
				return 1;
			}

			int num_events = 0;
			do
			{
				num_events = io_getevents(queue, 1, (std::min)(max_events, int(n)), events, NULL);

				for (int i = 0; i < num_events; ++i)
				{
					// reap iocb in events[i].obj
					if (events[i].res != buffer_size) {
						fprintf(stderr, "job returned %"PRId64": %s\n"
							, events[i].res, strerror(-events[i].res));
						exit(1);
					}
					++num_completed;
				}
				if (num_events > 0) n -= num_events;
			} while (num_events == max_events);
		}

		printf("%"PRId64"\t%d\t%d\n", time_now() - start_time, cursor, num_completed);
	}

	close(file);
	close(event);
	io_destroy(queue);

	free(buffer);
}