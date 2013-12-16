#include <vector>
#include <string>
#include <string.h>
using namespace std;

#define MX 1000000007
#define FF(i,n) for(i=0;i<n;i++)

int64 dist[2501][50][50];
int64 N;int M;

int64 dfs(int sum,int num,int cur)
{
	int64&val=dist[sum][num][cur];
	if(val==-1)
	{
		if(cur==M)
		{
			if(sum>N||(N-sum)%M!=0||num==0) val=0;
			else
			{
				/*C( Q + K - 1, K - 1) * K!*/
				int64 a=(N-sum)/M;val = num;int i;
	            for(i=0; i<num-1; i++)
	            {
	            	int64 b=(a+num-1-i)%MX;
	            	val=(val*b)%MX;
	            }
	          //  if(val<0) cout<<"("<<sum<<" "<<num<<" "<<cur<<" "<<val<<")";
			}
		}
		else val=(dfs(sum,num,cur+1)+dfs(sum+cur,num+1,cur+1))%MX;
	}
	//if(val<0&&val!=-1) cout<<"("<<sum<<" "<<num<<" "<<cur<<")";
    return val;
}

int howMany(int64 _N, int _M) 
{
	/*memset(dist,-1,sizeof(dist));*/
	int i,j,k;
	FF(i,2501) FF(j,50) FF(k,50) dist[i][j][k]=-1;

	N=_N;M=_M;return dfs(0,0,0);
}
