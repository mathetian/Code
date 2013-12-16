#include <vector>
#include <string>
#include <string.h>
using namespace std;

//not right idea?
/*int maxDamage(vector<int> const &level, vector<int> const &damage) 
{
	int n=level.size(),i,j;vector<int> flags(n,0);
	vector<int> d(n,0);vector<int> remain(n,0);
	for(i=0;i<n;i++) remain[i]=n-i;
	for(i=n-1;i>=0;i--)
	{
		int a=0,b=0;int k;
		for(j=i+1;j<n;j++)
		{
			if(flags.at(j)==0) a++;
			else
			{
				if(remain.at(j)+a>=level.at(i)-1) 
				{
					b=max(b,damage.at(i)+d.at(j));
					k=j;
				}
			}
		}

		if(b!=0)
		{
			flags[i]=1;d[i]=b;
		}
	}
    return 0;
}*/
/*
	dp[owned][index]: last is maybe index, the damage.
*/
/*
	direction is very important
	f(owned,last)=max(f(max(0,owned-1),last+1),f(owned+level[last]-1,last+1)+damgage[last]);
	constraint, 1. owned<=(n-index) 2. last<n. If break, f=zero. 
*/
vector<int> level, damage;int dp[2501][51];int n;

int dfs(int owned,int index)
{
	int&res=dp[owned][index];
	if(res==-1)
	{
		if(owned==n-index||index==n) res=0;
		else
		{
			res=dfs(max(0,owned-1),index+1);
			if(owned+level.at(index)-1<=n-index-1)
				res=max(res,dfs(owned+level.at(index)-1,index+1)+damage.at(index));
		}
	}
	return res;
}	

int maxDamage(vector<int> const &l, vector<int> const &d) 
{
	level=vector<int>(l.begin(),l.end());damage=vector<int>(d.begin(),d.end());
	n=level.size();memset(dp,-1,sizeof(dp));return dfs(0,0);
}
