#include <vector>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

#define MOD 1000000007
#define FF(i,n) for(i=0;i<n;i++)

/*int countArrangements(string const &cupcakes) 
{
	
		f(n),g(n) f(0)=3,g(0)?, f(1)=5 g(1)=3
		f(n)=f(n-1)+2*g(n-1)
		g(n)=n*f(n-1)
	
	vector<int>f(n,0);vector<int>g(n,0);
	f[0]=3;f[1]=5;g[1]=3;int n=cupcakes.size(),i;
	FF(i,n)
	{
		
	}
    return 0;
}*/

/**
	f(a,b,c,s,a)=f(a-1,b,c,s,!a)...
	Result: f(a,b,c,a,!a)+f(a,b,c,!b)+f(a,b,c,!c)
**/
typedef long long int64;
int64 dp[51][51][51][3][3];

int countArrangements(string const &cupcakes) 
{
	int num[3],i[3];memset(num,0,sizeof(num));int kk;FF(kk,cupcakes.size()) num[cupcakes.at(kk)-'A']++;
	//cout<<num[0]<<" "<<num[1]<<" "<<num[2]<<endl;
	memset(dp,0,sizeof(dp));dp[1][0][0][0][0]=1;dp[0][1][0][1][1]=1;dp[0][0][1][2][2]=1;int s,e,i0,j0;
	for(i[0]=0;i[0]<num[0]+1;i[0]++)
	{
		for(i[1]=0;i[1]<num[1]+1;i[1]++)
		{
			for(i[2]=0;i[2]<num[2]+1;i[2]++)
			{
				FF(s,3) FF(e,3)
				{
					if(s==e) if(i[s]<=1) continue; if(i[s]==0||i[e]==0) continue;
					int64&res=dp[i[0]][i[1]][i[2]][s][e];
					FF(i0,3)
					{
						if(i0!=e)
						{
							if(i0==s) if(i[0]+i[1]+i[2]-1>=2) if(i[s]<=1) continue;
							if(i[i0]<1) continue;
							if(e==0) res=(res+dp[i[0]-1][i[1]][i[2]][s][i0])%MOD;
							else if(e==1) res=(res+dp[i[0]][i[1]-1][i[2]][s][i0])%MOD;
							else res=(res+dp[i[0]][i[1]][i[2]-1][s][i0])%MOD;
						}
					}
					//cout<<"("<<i[0]<<" "<<i[1]<<" "<<i[2]<<" "<<s<<" "<<e<<" "<<res<<")";
				}
			}
		}
	}
	int64 rs=0;FF(i0,3) FF(j0,3) if(i0!=j0){rs=(rs+dp[num[0]][num[1]][num[2]][i0][j0])%MOD;} return rs;
}

/*int main()
{
	cout<<countArrangements("ABCABCABCC")<<endl;
	return 0;
}*/