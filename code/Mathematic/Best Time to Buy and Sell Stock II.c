class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int v1=0;int v2=0;
        for(int i=1;i<prices.size();i++)
        {
        	if(prices[i]>prices[i-1])
        		v2=v2+prices[i]-prices[i-1];
        	else
        	{
        		v1+=v2;
        		v2=0;
        	}
        }
        v1+=v2;
        return v1;
    }
};