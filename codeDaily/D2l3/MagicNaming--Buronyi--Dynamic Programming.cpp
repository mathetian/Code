#include <vector>
#include <string>
#include <string.h>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

int dp[51][51][51][51];

string magic;

int dfs(int start,int len)
{
	int&res=dp[start][magic.size()][start][len];
	if(res!=-1) return res;
	//cout<<"start:"<<start<<" len:"<<len<<endl;
	if(start+len==magic.size()) return 1;
	else
	{
		res=0;string str2=magic.substr(start,len);
		int mlen=magic.size()-start-len;
		for(int i=1;i<=mlen;i++)
		{
			string str=magic.substr(start+len,i);
			if(str2+str<=str+str2)
			{
				int b=dfs(start+len,i);
				if(b==0) continue;
				res=max(res,b+1);
			}
				
		}
	}
	//cout<<"start:"<<start<<" len:"<<len<<" res:"<<res<<endl;
	return res;
}

int maxReindeers(string const &magicName) 
{
	magic=magicName;memset(dp,-1,sizeof(dp));
	int n=magic.size();int len,mx=1;
	for(len=1;len<n;len++)
	{
		int a=dfs(0,len);
		//if(a==4) cout<<len<<endl;
		mx=max(a,mx);
	}
    return mx;
}
