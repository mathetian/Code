#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int capacity;int stationNum;int ordNum;int tmpMx;

typedef struct{
	int orgS;int desS;int num;int money;
}ORDER;

ORDER orders[23];
int remainMx[23];

int cmp(const ORDER d1,const ORDER d2)
{
	if(d1.orgS<d2.orgS)
		return 1;
	if(d1.orgS==d2.orgS)
		return d1.desS<d2.desS;
	return 0;
}

void dfs(int index,int tmpV)
{
//	printf("%d\n",tmpV);
	if(index==ordNum)
	{
		if(tmpV>tmpMx)
			tmpMx=tmpV;
		return;
	}
	int i;
	for(i=orders[index].orgS;i<orders[index].desS;i++)
	{
		if(remainMx[i]+orders[index].num>capacity)
			break;
	}
	if(i==orders[index].desS)
	{
		for(int j=orders[index].orgS;j<orders[index].desS;j++)
			remainMx[j]+=orders[index].num;
		dfs(index+1,tmpV+orders[index].money);
		for(int j=orders[index].orgS;j<orders[index].desS;j++)
			remainMx[j]-=orders[index].num;
	}
	dfs(index+1,tmpV);
}

int main()
{
	
	while(scanf("%d%d%d",&capacity,&stationNum,&ordNum)&&capacity!=0)
	{
		for(int i=0;i<ordNum;i++)
		{
			scanf("%d%d%d",&orders[i].orgS,&orders[i].desS,&orders[i].num);
			orders[i].money=(orders[i].desS-orders[i].orgS)*orders[i].num;
		}
		sort(orders,orders+ordNum,cmp);
		memset(remainMx,0,sizeof(int)*23);
		tmpMx=0;dfs(0,0);
		printf("%d\n",tmpMx);
	}
	return 0;
}