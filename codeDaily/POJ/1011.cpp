#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

#define N 65

int mxV;int data[N];int nums;int flag[N];
int eachVal;int total;int stickNum;

int dfs(int index,int need,int remain)
{
	if(remain==0&&need==0)
		return 1;
	else if(need==0)
	{	need=eachVal;index=0;}

	int i;
	for(i=index;i<nums;i++)
	{
		if(data[i]>need)
			continue;
		if(flag[i]==1)
			continue;
		flag[i]=1;
		if(dfs(i+1,need-data[i],remain-1))
			return 1;
		flag[i]=0;
		if(data[i]==need||need==eachVal)
			return 0;
	}
	return 0;
}

int cmp(const int a,const int b)
{
	return a>b;
}

int process()
{
	stickNum=total/eachVal;
	memset(flag,0,sizeof(int)*N);
	return dfs(0,eachVal,nums);
}

int main()
{
	while(scanf("%d",&nums)&&nums!=0)
	{
		total=0;
		for(int i=0;i<nums;i++)
		{
			scanf("%d",data+i);
			total+=data[i];
		}
		sort(data,data+nums,cmp);
	//	sort(data,data+nums);
		mxV=data[0];
	//	mxV=data[nums-1];int i;
		for(eachVal=mxV;eachVal<=total;eachVal++)
		{
			if(total%eachVal==0)
			{
				if(process())
				{
					printf("%d\n",eachVal);break;
				}
			}
		}
	}
	return 0;
}