class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >dp(2,vector<int>(prices.size(),0));
		int m=0x3fffffff;
		for(int i=0;i<prices.size();i++)
		{
			m=min(m,prices[i]);
			dp[0][i]=max(0,prices[i]-m);
		}        
		m=0;
		for(int i=prices.size()-1;i>=0;i--)
		{
			m=max(m,prices[i]);
			dp[1][i]=max(0,m-prices[i]);
		}
		m=0;
		for(int i=0;i<prices.size();i++)
			m=max(m,dp[0][i]+dp[1][i]);
		return m;
    }
};