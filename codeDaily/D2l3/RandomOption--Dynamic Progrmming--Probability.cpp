#include <vector>
#include <string>
#include <string.h>
using namespace std;

//probability problem

#define FF(i,n) for(i=0;i<n;i++)

double dp[1<<15][16];
int solved[1<<15][16];
int b[16][16];int keyCount;

double get(int mask,int last)
{
	double&res=dp[mask][last];int i;
	FF(i,keyCount) if((mask&(1<<i))!=0) break;
	if(i==keyCount) res=1.0;
	else if(!solved[mask][last])
	{
		double res2=0.0;int t=0;
		FF(i,keyCount)
		{
			if((mask&(1<<i))!=0)
			{
				t++;if(b[last][i]==1||b[i][last]==1) 
				continue;res2+=get(mask^(1<<i),i);
			}
		}
		if(t==0) res=0; else res=res2/(double)t;
		solved[mask][last]=1;
	}
	return res;
}

double getProbability(int k,vector<int> const &badLane1,vector<int> const &badLane2) 
{
	memset(solved,0,sizeof(solved));memset(dp,0,sizeof(dp));int i,j;memset(b,0,sizeof(b));
	FF(i,badLane1.size()) b[badLane1.at(i)][badLane2.at(i)]=1;keyCount=k;
	return get((1<<keyCount)-1,keyCount);
}
