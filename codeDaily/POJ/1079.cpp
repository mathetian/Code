
#include<stdio.h>
#include<math.h>

double getDiv(double v1,double v2)
{
	return v1/v2;
}

int isInt(double n)
{
	if(ceil(n)==(int)n)
		return 1;
	return 0;
}

int main()
{
	int winner;int loser;
	while(scanf("%d%d",&winner,&loser)!=EOF)
	{
		if(winner==0)
		{
			printf("0/1\n\n");continue;
		}
		double result=getDiv(winner,loser);
		double oldwinner=result;
		oldwinner=floor(oldwinner+0.5);
		printf("%d/%d\n",(int)oldwinner,1);
		int oldloser=1;
		double near=fabs(getDiv(oldwinner,oldloser)-result);
		int eglibeW=oldwinner;int eglibeL=oldloser;
		while(oldloser!=loser)
		{
			if(oldloser==3)
				while(0);
			double n=getDiv(oldloser+1,eglibeL)*eglibeW;
			if(isInt(n)==1)
			{
				double n1=fabs(getDiv(n-1,oldloser+1)-result);
				double n2=fabs(getDiv(n+1,oldloser+1)-result);
				if(n1<n2&&n1<near)
				{
					printf("%d/%d\n",(int)n-1,oldloser+1);
					near=n1;
					eglibeW=n-1;eglibeL=oldloser+1;
				}
				else if(n2<n1&&n2<near)
				{
					printf("%d/%d\n",(int)n+1,oldloser+1);
					near=n2;
					eglibeW=n+1;eglibeL=oldloser+1;
				}
			}
			else
			{
				double n1=fabs(getDiv(floor(n),oldloser+1)-result);
				double n2=fabs(getDiv(ceil(n),oldloser+1)-result);
				if(n1<n2&&n1<near)
				{
					printf("%d/%d\n",(int)floor(n),oldloser+1);
					eglibeW=floor(n);eglibeL=oldloser+1;
					near=n1;
				}
				else if(n2<n1&&n2<near)
				{
					printf("%d/%d\n",(int)ceil(n),oldloser+1);
					eglibeW=ceil(n);eglibeL=oldloser+1;
					near=n2;
				}
			}
			oldloser++;
		}
		putchar('\n');
	}
	return 0;
}