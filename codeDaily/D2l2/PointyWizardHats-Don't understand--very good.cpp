#include <vector>
#include <string>
#include <string.h>
using namespace std;

/*int mx;
void dfs(vector<vector<int> >&dp,vector<int> flag,int index,int n,int m,int tmp)
{
	if(index==n) mx=max(mx,tmp);
	else
	{
		dfs(dp,flag,index+1,n,m,tmp);
		vector<int> dp1=dp.at(index);
		for(int i=0;i<dp1.size();i++)
		{
			int v=dp1.at(i);
			if(flag[v]==0)
			{
				flag[v]=1;
				dfs(dp,flag,index+1,n,m,tmp+1);
				flag[v]=0;
			}
		}
	}
}*/

int n,m;int match[50];char dp[50][50];
char vis[50];

int find(int x)
{
	int i;
	for(i=0;i<m;i++)
	{
		if(dp[x][i]==1&&vis[i]==0)
		{
			vis[i]=1;
			if(match[i]==-1||find(match[i]))
			{
				match[i]=x;
				return 1;
			}
		}
	}
	return 0;	
}

int getNumHats(vector<int> const &topHeight,
               vector<int> const &topRadius,
               vector<int> const &bottomHeight,
               vector<int> const &bottomRadius) {
   	memset(dp,0,2500);n=topHeight.size();
   	m=bottomHeight.size();int i,j;
   	
   	for(i=0;i<n;i++)
   	{
   		for(j=0;j<m;j++)
   		{
   			if(topRadius.at(i)>=bottomRadius.at(j)) continue;
   			if(topHeight.at(i)*bottomRadius.at(j)>bottomHeight.at(j)*topRadius.at(i)) dp[i][j]=1;
   		}
   	}
   	memset(match,-1,50*sizeof(int));int cnt=0;
   	for(i=0;i<n;i++)
   	{
   		memset(vis,0,50);
   		if(find(i)==1) cnt++;		
   	}
    return cnt;
}
