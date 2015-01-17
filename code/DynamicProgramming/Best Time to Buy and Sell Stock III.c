class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >dp(2,vector<int>(prices.size(),0));	
        int minVal=0x3fffffff;int mxProfit=0;
        for(int i=0;i<prices.size();i++)
        {	
        	minVal=min(minVal,prices[i]);
        	mxProfit=max(mxProfit,prices[i]-minVal);
        	dp[0][i]=mxProfit;
        }
        int maxVal=-0x3fffffff;mxProfit=0;
        for(int i=prices.size()-1;i>=0;i--)
        {
        	maxVal=max(maxVal,prices[i]);
        	mxProfit=max(mxProfit,maxVal-prices[i]);
        	dp[1][i]=mxProfit;
        }
        mxProfit=0;
        for(int i=0;i<prices.size();i++)
        	mxProfit=max(mxProfit,dp[0][i]+dp[1][i]);
        return mxProfit;
    }
};