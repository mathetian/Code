#include <vector>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

/*int64 dp[555][555][2];*/

/*
	dp[n][m][0]=dp[n-1][m][0]+dp[n-2][m][1]+dp[n-2][m][0]+dp[n-2][m-1][0]
	dp[n][m][1]=dp[n-1][m][1]+dp[n-2][m-1][1], m<=n-1
*/
/*int theCount(int N,int muddyCount) 
{
	memset(dp,0,sizeof(dp));int n,m;
	dp[1][0][0]=0;dp[1][0][1]=1;dp[0][0][1]=1;

	for(n=1;n<N;n++)
	{
		if(n==0) continue;
		FF(m,max(n,muddyCount+1))
		{
			int64&res=dp[n][m][0];res=dp[n-1][m][0];
			if(n-2>=0) res=(res+dp[n-2][m][0]+dp[n-2][m][1])%MOD;
			if(n-2>=0&&m-1>=0) res=(res+dp[n-2][m-1][0])%MOD;
			int64&res2=dp[n][m][1];res2=dp[n-1][m][1];
			if(n-2>=0&&m-1>=0) res2=(res2+dp[n-2][m-1][1])%MOD;
		}
	}
    return dp[N-1][muddyCount][0];
}*/

#define MOD 555555555
#define FF(i,n) for(i=0;i<n;i++)
#define FFS(i,a,b) for(i=a;i<b;i++)

typedef long long int64;

/**
	p1, n clear cell, even or odd?
	p2,	give a situation, check it
	p3, how to place to get even ways

	a1, n%3==0 even
	a2, constitute not possible(zero, so even). other, if n_i%3==0, get it.
	a3, what we need in this problem
**/
/**
	dp[a][b][c]=dp[a-1][b-1][0,1]
	dp[a][b][c]=dp[a][b][x]
**/
int64 dp[556][556][3];
int64 get(int a,int b,int lm)
{
	int64&res=dp[a][b][lm];if(res!=-1) return res;
	if(b==0) 
	{
		res=0;if(a%3==lm)res=1;
	}
	else
	{
		res=(get(a-lm,b-1,1)+get(a-lm,b-1,2))%MOD;
		if(a>=3) res=(res+get(a-3,b,lm))%MOD;
	}
	
	cout<<"("<<a<<" "<<b<<" "<<lm<<" "<<res<<")";
	return res;
}

int theCount(int N,int muddyCount) 
{

	int i,j,k;memset(dp,-1,sizeof(dp));
	get(N-muddyCount,muddyCount,1);get(N,muddyCount,2);
	int64 cc[556][556];memset(cc,0,sizeof(cc));
	cout<<"end??"<<endl;
	FFS(i,1,N-1) FF(j,min(muddyCount,i)+1){if(j==0||j==i)cc[i][j]=1;else cc[i][j]=(cc[i-1][j]+cc[i-1][j-1])%MOD;}
	return (cc[N-2][muddyCount]-dp[N-muddyCount][muddyCount][1]-dp[N-muddyCount][muddyCount][2]+MOD)%MOD;
}