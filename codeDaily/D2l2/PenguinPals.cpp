#include <vector>
#include <string>
using namespace std;

int get(string const &colors,int start,int end,vector<vector<int> >&dp)
{
	if(start>=end) return 0;
	if(dp[start][end]!=-1) return dp[start][end];
	dp[start][end]=get(colors,start+1,end,dp);
	for(int i=start+1;i<=end;i++)
	{
		if(colors.at(i)==colors.at(start))
		{
			int v=get(colors,start+1,i-1,dp)+get(colors,i+1,end,dp)+1;
			dp[start][end]=max(dp[start][end],v);
		}
	}
	return dp[start][end];
}

int findMaximumMatching(string const &colors) {
    vector<vector<int> >dp(colors.size(),vector<int>(colors.size(),-1));
    return get(colors,0,colors.size()-1,dp);
}


