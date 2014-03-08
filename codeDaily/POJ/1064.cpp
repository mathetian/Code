#include<stdio.h>
#include<algorithm>
using namespace std;

#define EPS 1e-2

int main()
{
	int cableNum;int needNum;int cables[10001];
	while(scanf("%d%d",&cableNum,&needNum)!=EOF)
	{
		double tmp;
		for(int i=0;i<cableNum;i++)
		{
			scanf("%lf",&tmp);cables[i]=tmp*100;
		}
		sort(cables,cables+cableNum);
		int min=0;int mx=cables[cableNum-1];
		while(mx-min>1)
		{
			int q=(mx+min)/2;
			int now=0;
			for(int i=0;i<cableNum;i++)
				now+=cables[i]/q;
			if(now>=needNum)
				min=q;
			else
				mx=q;
		}
		int now=0;
		for(int i=0;i<cableNum;i++)
			now+=cables[i]/mx;
		if(now>=needNum)
			printf("%0.2f\n",mx/100.0);
		else
		{
			if(min==0)
				printf("0.00\n");
			else
				printf("%0.2f\n",min/100.0);
		}
	}
	return 0;
}