/**
	Question, https://sites.google.com/site/spaceofjameschen/home/recursion/find-the-subset-whose-sum-is-exactly-half-of-the-total-sum----yahoo

	Solution, http://en.wikipedia.org/wiki/Subset_sum_problem

	Dynamic Programming & NP problems.
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

void findsubset(vector<int>&arr,int target)
{
	int mx=0,mn=0;int sum=0;
	for(unsigned int i=1;i<arr.size();i++)
	{
		if(mx>0) mx=mx+arr[i];
		else mn=mn+arr[i];
	}
	if(target>mx) return;
	vector<vector<int> >dp(arr.size(),vector<int>(mx-mn+1,0));;
	dp[0][arr[0]-mn]=1;
	//dp[i][j]=dp[i-1][j-arr[i]] || dp[i-1][j] || (arr[i]==j)
	for(unsigned int i=1;i<arr.size();i++)
	{
		for(int j=0;j<=mx-mn+1;j++)
		{
			if(j>arr[i]) dp[i][j] |=dp[i-1][j-arr[i]];
			if(j==arr[i]) dp[i][j]=1;
			dp[i][j]|=dp[i-1][j];
		}
	}


}

void DoTest()
{
	
}

int main()
{
	return 0;
}