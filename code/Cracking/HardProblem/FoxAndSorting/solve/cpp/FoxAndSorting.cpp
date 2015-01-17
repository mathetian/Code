#include <vector>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

typedef long long int64;

int64 dp[181][19];

int64 dfs(int num,int lenmx)
{
	int64&res=dp[num][lenmx];int i;
	if(res!=-1) return res;
	if(lenmx==1) if(num>=10) 
	res=0;else res=1;
	else if(num==0) res=1; else
	{
		res=0;FF(i,10) if(i>num) break; 
		else res+=dfs(num-i,lenmx-1);
	}
	return res;
}

int64 get1(int i)
{
	int64 res=1;while(--i>=0) 
	res=res*10;return res;
}

int64 get(int64 idx) 
{
	int sum,i,j;memset(dp,-1,sizeof(dp));
	FF(sum,163) dfs(sum,18);
	FF(sum,163) cout<<"sum:"<<sum<<" "<<dfs(sum,18)<<endl;
	sum=0;while(idx-dp[sum][18]>0)
	{ idx-=dp[sum][18];sum++; }
	int64 res2=0;int lenmx=18;
	while(idx!=0)
	{
		int64 num=0;FF(j,10)
		{
			if(sum<j) break;
			if(num+dfs(sum-j,lenmx-1)>idx) break;
			num+=dfs(sum-j,lenmx-1);
		}
		idx-=num;res2=get1(18-lenmx)*j+res2;sum=sum-j;
		lenmx--;
	}
    return res2;
}

int main()
{
	cout<<get(58)<<endl;
	return 0;
}