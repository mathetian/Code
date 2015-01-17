#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)
#define INF 0x3fffff

int n,a,b;
vector<int> ivec;
vector<int> dp;

int getdp(int index)
{
	if(dp.at(index) != -INF)
		return dp.at(index);
	int ans = INF;
	for(int j=index+1;j<n;j++)
	{
		if(ivec.at(j) - ivec.at(index) >= a && ivec.at(j) - ivec.at(index) <= b)
		{
			ans = min(ans, ivec.at(index) - getdp(j));
		}
	}
	if(ans == INF)
		dp[index] = ivec.at(index);
	else
		dp[index] = ans;
	return dp.at(index);
}

int main()
{
	int case1; cin>>case1;

	while(case1--)
	{
		cin>>n>>a>>b;
		ivec = vector<int>(n,0);
		dp   = vector<int>(n,-INF);
		int i;FF(i,n) cin>>ivec[i];
		sort(ivec.begin(),ivec.end());
		int ans = -INF;
		FF(i,n)
		{
			if(ivec.at(i) >= a && ivec.at(i) <= b)
				ans = max(ans, getdp(i));
		}
		cout<<ans<<endl;
	}
	return 0;
}