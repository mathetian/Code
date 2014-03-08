#include<stdio.h>
double val[500];
int main()
{
	val[1]=0;
	for(int i=2;i<500;i++)
	{
		val[i]=val[i-1]+1.0/i;
	}
	double vl;
	while(scanf("%lf",&vl)&&vl!=0)
	{
		for(int j=2;j<500;j++)
		{
			if(val[j]>=vl)
			{
				printf("%d card(s)\n",j-1);
				break;
			}
		}
	}
	return 0;
}