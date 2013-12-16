#include <vector>
#include <string>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

//How to understand dynamic programming for this problem?
//First, summary the formual.
//Second, find the minium value which was possible.
//Dynamic programming?
//Solution, dp[t][i]: from t to n, assume can fill with i. the minium value.
int calc(vector<int> const &A, vector<int> const &B) 
{
	int sum=0;int i,n=A.size();
	int ta=0, tb=0;vector<int> C;
	FF(i,n)
	{
		C.push_back(A.at(i)+B.at(i));
		ta+=A.at(i);tb+=B.at(i);sum+=C.at(i);
	}
	vector<int>dp(sum+1,0);int j;
	FF(i,sum+1) dp[i]=max(i-ta,tb-i);
	FF(i,n)
	{
		for(j=0;j<=sum;j++)
		{
			int res=dp.at(j);
			if(j+C.at(i)<=sum) 
				res=min(res,dp.at(j+C.at(i)));	
			dp[j]=res;
		}
	} 
    return dp[0];
}