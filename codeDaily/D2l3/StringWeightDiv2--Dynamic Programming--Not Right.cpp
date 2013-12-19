#include <vector>
#include <string>
#include <string.h>
using namespace std;

#define MX 1000000009

long long dp[27][1001];
long long ff(int a,int L)
{
	long long&res=dp[a][L];
	if(res==-1)
	{	
		if(L==0) res=(a==0);
		else if(a==1) res=1;
		else
		{
			res=0;
			for(int i=1;i<=L;i++)
				res=(res+a*ff(a-1,L-i))%MX;
		}
	}
	return res;
}

int countMinimums(int L) 
{
	if(L<=26)
	{
		long long ll=1;
		for(int i=0;i<L;i++)
			ll=(ll*(26-i))%MX;
		return ll;
	}
	memset(dp,-1,sizeof(long)*27*1001);
    return ff(26,L);
}
