#include<stdio.h>
#include<string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define SZ 102
#define FF(i,n) for(i = 0;i < n; i++)

int maps[SZ][SZ], sum[SZ][SZ];
int dp[SZ];

int main()
{
	int n, i, j, k, mx, flag, prev;

	while(cin>>n)
	{
		memset(maps,0,sizeof(maps));
		memset(sum,0,sizeof(sum));

		FF(i,n) FF(j,n) cin>>maps[i][j];

		FF(j,n)
		{
			sum[n-1][j] = maps[n-1][j];
			for(i = n-2;i >= 0;i--)
				sum[i][j] = sum[i+1][j] + maps[i][j];
		}

		mx = 0;

		for(k = 1;k <= n; k++)
		{
			for(i = 0;i + k - 1 < n;i++)
			{
				/**
					a[j] = sum[i][j] - sum[i+k][j]
				**/
				prev = max(0,sum[i][j] - sum[i+k][j]);
				for(j = 0;j < n;j++)
				{
					mx = max(mx, prev + sum[i][j] - sum[i+k][j]);
					prev = max(0, prev + sum[i][j] - sum[i+k][j]);
				}
			}
		}

		if(mx == 0)
		{
			mx = maps[0][0];
			FF(i,n) FF(j,n) mx = max(mx,maps[i][j]);
		}
		printf("%d\n",mx);
	}
	return 0;
}