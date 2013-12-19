#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)


int64 count(vector<int> const &ski) 
{
	vector<int> skill(ski.begin(),ski.end());
	int n=skill.size();int64 i,j;int64 sum=0;
	sort(skill.begin(),skill.end());
	reverse(skill.begin(),skill.end());
	FF(i,n) sum+=skill.at(i);int64 ans=0;
	vector<int64> dp(sum+1,0);dp[0]=1;
	FF(i,n)
	{
		for(j=sum;j>=skill.at(i);j--)
		{
			dp[j]+=dp[j-skill.at(i)];
			if((2*j)>sum&&2*(j-skill.at(i))<sum)
				ans+=dp[j-skill.at(i)];
		}	
	}
	return ans;
}