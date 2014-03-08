// Copyright 2012 Google Inc. All Rights Reserved
// Author: dehrenberg@google.com (Daniel Ehrenberg)

// g++ test.cpp -lrt -laio

#include <fcntl.h>
#include <libaio.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>
using namespace std;

#define DEFINE_string(a,b,c) string FLAGS_##a = b
#define DEFINE_int32(a,b,c) int FLAGS_##a = b

DEFINE_string(path, "/tmp/testfile", "Path to the file to manipulate");
DEFINE_int32(file_size, 1000, "Length of file in 4k blocks");
DEFINE_int32(concurrent_requests, 100, "Number of concurrent requests");
DEFINE_int32(min_nr, 1, "min_nr");
DEFINE_int32(max_nr, 1, "max_nr");

// The size of operation that will occur on the device
static const int kPageSize = 4096;




class AIORequest {
 public:
  int* buffer_;

  virtual void Complete(int res) = 0;

  AIORequest() {
    int ret = posix_memalign(reinterpret_cast<void**>(&buffer_),
                             kPageSize, kPageSize);
  }

  virtual ~AIORequest() {
    free(buffer_);
  }
};

class Adder {
 public:
  virtual void Add(int amount) = 0;

  virtual ~Adder() { };
};

class AIOReadRequest : public AIORequest {
 private:
  Adder* adder_;

 public:
  AIOReadRequest(Adder* adder) : AIORequest(), adder_(adder) { }

  virtual void Complete(int res) {
    int value = buffer_[0];
    adder_->Add(value);
  }
};

class AIOWriteRequest : public AIORequest {
 private:
  int value_;

 public:
  AIOWriteRequest(int value) : AIORequest(), value_(value) {
    buffer_[0] = value;
  }

  virtual void Complete(int res) {
    if(res == kPageSize) 
      printf("Write incomplete or error %d" ,res);
  }
};

class AIOAdder : public Adder {
 public:
  int fd_;
  io_context_t ioctx_;
  int counter_;
  int reap_counter_;
  int sum_;
  int length_;

  AIOAdder(int length)
      : ioctx_(0), counter_(0), reap_counter_(0), sum_(0), length_(length) { }

  void Init() {
    fd_ = open(FLAGS_path.c_str(), O_RDWR | O_DIRECT | O_CREAT, 0644);
    fallocate(fd_, 0, 0, kPageSize * length_);
    io_setup(100, &ioctx_);
  }

  virtual void Add(int amount) {
    sum_ += amount;
  }

  void SubmitWrite() {
    struct iocb iocb;
    struct iocb* iocbs = &iocb;
    AIORequest *req = new AIOWriteRequest(counter_);
    io_prep_pwrite(&iocb, fd_, req->buffer_, kPageSize, counter_ * kPageSize);
    iocb.data = req;
    int res = io_submit(ioctx_, 1, &iocbs);
  }

  void WriteFile() {
    reap_counter_ = 0;
    for (counter_ = 0; counter_ < length_; counter_++) {
      SubmitWrite();
      Reap();
    }
    ReapRemaining();
  }

  void SubmitRead() {
    struct iocb iocb;
    struct iocb* iocbs = &iocb;
    AIORequest *req = new AIOReadRequest(this);
    io_prep_pread(&iocb, fd_, req->buffer_, kPageSize, counter_ * kPageSize);
    iocb.data = req;
    int res = io_submit(ioctx_, 1, &iocbs);
  }

  void ReadFile() {
    reap_counter_ = 0;
    for (counter_ = 0; counter_ < length_; counter_++) {
        SubmitRead();
        Reap();
    }
    ReapRemaining();
  }

  int DoReap(int min_nr) {
    struct io_event* events = new io_event[FLAGS_max_nr];
    struct timespec timeout;
    timeout.tv_sec = 0;
    timeout.tv_nsec = 100000000;
    int num_events;
    num_events = io_getevents(ioctx_, min_nr, FLAGS_max_nr, events, &timeout);
    for (int i = 0; i < num_events; i++) {
      struct io_event event = events[i];
      AIORequest* req = static_cast<AIORequest*>(event.data);
      req->Complete(event.res);
      delete req;
    }
    delete events;
    
    reap_counter_ += num_events;
    return num_events;
  }

  void Reap() {
    if (counter_ >= FLAGS_min_nr) {
      DoReap(FLAGS_min_nr);
    }
  }

  void ReapRemaining() {
    while (reap_counter_ < length_) {
      DoReap(1);
    }
  }

  ~AIOAdder() {
    io_destroy(ioctx_);
    close(fd_);
  }

  int Sum() {
    WriteFile();
    ReadFile();
    return sum_;
  }
};

int main(int argc, char* argv[]) {
  AIOAdder adder(FLAGS_file_size);
  adder.Init();
  int sum = adder.Sum();
  int expected = (FLAGS_file_size * (FLAGS_file_size - 1)) / 2;
  printf("Successfully calculated that the sum of integers from 0"
         " to %d is %d\n", FLAGS_file_size - 1, sum);
  return 0;
}