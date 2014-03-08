#include <vector>
#include <string>
using namespace std;

int numSolutions(int N, int M) 
{
    return 0;
}

const int64 mod = 1000000007;
int64 jiou[1<<8],dp[2][1<<8][(1<<8)];

int numSolutions(int n, int m)
{
	int yihuo = (1<<m)-1,tot=1<<m;
	for(int i=0; i<tot; i++)
	{
		jiou[i] = 0;
		for(int j=0; j<m; (j++))
		{
			if( !((1<<j)&i)) continue;
			if(j>0 && i&(1<<(j-1))){
				jiou[i]^=(1<<j);
			}
			if(j<m-1 && (i&(1<<(j+1)))){
				jiou[i]^=(1<<j);
			}
		}
	}
	memset(dp,0,sizeof(dp));
	for(int i=0; i<tot; i++)
		dp[0][i][jiou[i]] ++;
	int add;
	for(int i=0; i<n-1; i++)
	{
		for(unsigned int t=0; t<tot; t++)
		{
			for(unsigned int j=0; j<tot; j++)
			{
				if(dp[0][t][j]>0)
				{//这句很重要。
					//cout<<t<<' '<<j<<endl;;
					for(unsigned int k=0; k<tot; k++)
					{

						//cout<<"chk "<<t<<' '<<j<<' '<<k<<endl;
						//cout<<"yes "<<(t&(~j))<<' '<<(k&(t&(~j)))<<endl;
						//cout<<"ye2 "<<(k&j)<<' '<<j<<endl;
						if((k&j)==j  && !(k&(t&(~j))) )
						{
							add = (jiou[k]^t)&k;
							//cout<<"add "<<add<<' '<<k<<endl;;
							dp[1][k][add] += dp[0][t][j];
							if(dp[1][k][add]>=mod)
								dp[1][k][add] -= mod;
						}
					}
				}
			}
		}
		for(int t=0; t<tot; t++)
			for(int j=0; j<tot; j++)
			{
				dp[0][t][j] = dp[1][t][j];
				dp[1][t][j] = 0;
			}
	}
	int64 ret = 0;
	for(int i=0; i<tot; i++)
		ret = (ret+dp[0][i][0])%mod;
	return ret;
}