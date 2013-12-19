#include <vector>
#include <string>
#include <string.h>
using namespace std;

#define MOD 1000000007

vector<int>astart;vector<int>aend;
vector<int>bstart;vector<int>bend;

int64 dp[51][51][51][51];

int64 get(int a,int b,int c,int d)
{
	int64&res=dp[a][b][c][d];
	if(res!=-1) return res;
	if(a==0&&b==0&&c==0&&d==0) res=1;
	else
	{
		res=0;if(a!=0)
		{
			if(c!=0&&astart.at(a-1)==aend.at(c-1)) res=(res+get(a-1,b,c-1,d))%MOD;
			if(d!=0&&astart.at(a-1)==bend.at(d-1)) res=(res+get(a-1,b,c,d-1))%MOD;
		}
		if(b!=0)
		{
			if(c!=0&&bstart.at(b-1)==aend.at(c-1)) res=(res+get(a,b-1,c-1,d))%MOD;
			if(d!=0&&bstart.at(b-1)==bend.at(d-1)) res=(res+get(a,b-1,c,d-1))%MOD;
		}
	}
	return res;
}

int countWays(vector<int> const &AliceStart, vector<int> const &BobStart, vector<int> const &AliceEnd, vector<int> const &BobEnd) 
{
	astart=vector<int>(AliceStart.begin(),AliceStart.end());aend=vector<int>(AliceEnd.begin(),AliceEnd.end());
	bstart=vector<int>(BobStart.begin(),BobStart.end());bend=vector<int>(BobEnd.begin(),BobEnd.end());
	memset(dp,-1,sizeof(dp));get(AliceStart.size(),BobStart.size(),AliceEnd.size(),BobEnd.size());
    return dp[AliceStart.size()][BobStart.size()][AliceEnd.size()][BobEnd.size()];
}
