#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
using namespace std;

typedef struct{
	int badth;
	int price;
}DEV;

int cmp(const DEV p1,const DEV p2)
{
	if(p1.badth<p2.badth)
		return 1;
	else if(p1.badth==p2.badth&&p1.price<p2.price)
		return 1;
	else
		return 0;
}

int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		int deviceNum;
		scanf("%d",&deviceNum);
		int devNum[100];DEV devices[100][100];
		int minNum=0x7f7f7f7f;int maxNum=-1;
		for(int i=0;i<deviceNum;i++)
		{
			scanf("%d",devNum+i);
			for(int j=0;j<devNum[i];j++)
				scanf("%d%d",&devices[i][j].badth,&devices[i][j].price);
			sort(devices[i],devices[i]+devNum[i],cmp);
			if(minNum>devices[i][0].badth)
				minNum=devices[i][0].badth;
			if(maxNum>devices[i][devNum[i]-1].badth||maxNum==-1)
				maxNum=devices[i][devNum[i]-1].badth;
		}
		int Cur[100];
		memset(Cur,0,sizeof(int)*100);
		int result;double res=0;int b;
		for(int minSel=minNum;minSel<=maxNum;minSel=b+1)
		{
			int priceTotal=0;b=0x7f7f7f7f;
			int i,j;
			for(i=0;i<deviceNum;i++)
			{
				for(j=Cur[i];j<devNum[i];j++)
				{
					if(devices[i][j].badth>=minSel)
						break;
				}
				Cur[i]=j;
				int priceTmp=devices[i][j].price;
				int k=j;
				for(;j<devNum[i];j++)
				{
					if(devices[i][j].price<priceTmp)
					{
						priceTmp=devices[i][j].price;k=j;
					}
				}
				priceTotal+=priceTmp;
				b=min(b,devices[i][k].badth);
			}
			if(res<((double)b)/priceTotal)
			{
				res=((double)b)/priceTotal;
			}
		}
		printf("%0.3f\n",res);
	}
}