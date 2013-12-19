#include <vector>
#include <string>
#include <string.h>
using namespace std;

/*direction is very important and difficult
the longest way from each node. We can block every node.
direction is left and then direction won't be right*/
/**
	f(x,y,d)=max(f(x+1,y,0),f(x,y-1,1),f(x,y+1,2))
	Constraint: 1. x<n 2. won't block 3. allowable direction
	One confusing, duplicate calculate?
**/
#define INF 0x3fffff

vector<string> costs;int n,m;
int dp[50][50][3];

int dfs(int x,int y,int d)
{
	int&res=dp[x][y][d];
	if(res==-1)
	{
		if(costs[x][y]=='x') res=-0x3fffff;
		else
		{
			if(x==n-1) res=0;
			else
			{
				int a=dfs(x+1,y,0),b=a,c=a;
				/*if(d==0||(d==1&&y>=1)) b=dfs(x,y-1,1);
				if(d==0||(d==2&&y<m-1)) c=dfs(x,y+1,2);*/
				if(d!=2&&y>=1) b=dfs(x,y-1,1);
				if(d!=1&&y<m-1) c=dfs(x,y+1,2);
				res=max(a,max(b,c));
			}
			res+=costs[x][y]-'0';
		}
	}
	return res;
	
}

int play(vector<string> const &c) 
{
	costs=vector<string>(c.begin(),c.end());n=c.size();m=c.at(0).size();
	memset(dp,-1,sizeof(dp));return dfs(0,0,0);
}
