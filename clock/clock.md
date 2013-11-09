In windows, we can use GetTickCount to get the time.

In linux, three ways have been found. We must notice that there are some traps in multi-thread atmosphere.

First way,
`clock_t t1=clock();`
`clock_t t2=clock();`
`cout<<"t1:"<<t1<<" t2:"<<t2<<" t2-t1:"<<(t2-t1)/CLOCKS_PER_SEC<<endl;`

Second way,

`struct timespec{`
`      time_t tv_sec; /*second*/`
`      long tv_nsec;/*nanosecond*/`
`}`

`typedef struct timespec _timespec;`

`_timespec diff(_timespec start, _timespec end)`
`{`
`	_timespec temp;`
`	if((end.tv_nsec-start.tv_nsec)<0)`
`	{`
`		temp.tv_sec=end.tv_sec-start.tv_sec-1;`
`		temp.tv_nsec=1000000000+end.tv_nsec-start.tv_nsec;`
`	}`
`	else`
`	{`
`		temp.tv_sec=end.tv_sec-start.tv_sec;`
`		temp.tv_nsec=end.tv_nsec-start.tv_nsec;`
`	}`
`	return temp;`
`}`

`clock_gettime(CLOCK_MONOTONIC,&time1);`

Third way,

`struct timeval tstart, tend;`
`gettimeofday(&tstart, NULL);`
`gettimeofday(&tend, NULL);`
`long int uses = 1000000 * (tend.tv_sec - tstart.tv_sec) + (tend.tv_usec - tstart.tv_usec);`
`printf("loop time: %lld\n", uses); `

