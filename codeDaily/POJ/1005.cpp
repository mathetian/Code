#include<stdio.h>
#include<math.h>

#define PI 3.1415926
int main()
{
	//Property 1: This property will begin eroding in year 1.
	//Property 2: This property will begin eroding in year 20.
	//END OF OUTPUT.
	int nums;
	scanf("%d",&nums);int index=1;
	while(nums--)
	{
		double t1,t2;
		scanf("%lf%lf",&t1,&t2);
		//t1=t1*t1+t2*t2;
		//t1=PI*t1/100.0;
		int v=ceil(PI*(t1*t1+t2*t2)/100.0);
		printf("Property %d: This property will begin eroding in year %d.\n",index,v);
		index++;
	}
	printf("END OF OUTPUT.\n");
	return 0;
}