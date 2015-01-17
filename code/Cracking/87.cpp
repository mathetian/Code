#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include <string.h>

int arr[]={1,5,10,25};
int dp[1000][4];

int get(int n,int k)
{
	if(dp[n][k]!=-1)
		return dp[n][k];
	int&t=dp[n][k];
	if(n<arr[k]) t=0;
	else if(k==0) t=n;
	else t=get(n,k-1)+get(n-1,k);
	reutrn t;
}

int makeChange(int n)
{
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<=4;i++)
		dp[0][i]=0;
	return get(n,3);
}

int main()
{
	return 0;
}