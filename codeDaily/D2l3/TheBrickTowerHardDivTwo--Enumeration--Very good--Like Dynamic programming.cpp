#include <vector>
#include <string>
#include <string.h>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)
#define MOD 1234567891

int64 dp[4][4][4][4][8][48];int C,K,H;

int64 dfs(int a,int b,int c,int d,int target,int level)
{
	int64&res=dp[a][b][c][d][target][level];
	if(res!=-1) return res;int i,j,k,l;
	int aa=(a==b)+(b==c)+(c==d)+(d==a);res=0;
	if(level==1) res=(aa==target);
	else if(target<aa) res=0;else
	{
		int bb=0;
		FF(i,C) FF(j,C) FF(k,C) FF(l,C)
		{
			int bb=(i==a)+(j==b)+(k==c)+(l==d);
			if(aa+bb>target) continue;
			res=(res+dfs(i,j,k,l,target-aa-bb,level-1))%MOD;
		}
		
	}
	return res;
}

void generate()
{
	int i,j,k,l;int target,level;
	for(level=1;level<=H;level++)
	{
		FF(i,C) FF(j,C) FF(k,C) FF(l,C) 
		FF(target,K+1) dfs(i,j,k,l,target,level);
	}
}

int64 count()
{
	int i,j,k,l;int target,level;int ans=0;
	for(level=1;level<=H;level++)
	FF(i,C) FF(j,C) FF(k,C) FF(l,C) FF(target,K+1)
	{
		//cout<<"("<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<target<<" "<<level<<" "<<dfs(i,j,k,l,target,level)<<")";
		/*if(dfs(i,j,k,l,target,level)==1)
		{
			cout<<"("<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<target<<" "<<level<<" "<<dfs(i,j,k,l,target,level)<<")";
		}*/
		ans=(ans+dfs(i,j,k,l,target,level))%MOD;
	}
	return ans;
	
}

int find(int C1, int K1, int H1) 
{
	C=C1;K=K1;H=H1;memset(dp,-1,sizeof(dp));
	generate();return count();
}
