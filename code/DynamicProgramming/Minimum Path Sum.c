class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(grid.size()==0)
        	return 0;
        else if(grid[0].size()==0)
        	return 0;
       int**dp=new int*[grid.size()];
       for(int i=0;i<grid.size();i++)
       		dp[i]=new int[grid[0].size()];
       	dp[0][0]=grid[0][0];
       	for(int i=1;i<grid.size();i++)
       		dp[i][0]=dp[i-1][0]+grid[i][0];
       	for(int i=1;i<grid[0].size();i++)
       		dp[0][i]=dp[0][i-1]+grid[0][i];
       	for(int i=1;i<grid.size();i++)
       	{
       		for(int j=1;j<grid[i].size();j++)
       			dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
       	}
       	return dp[grid.size()-1][grid[0].size()-1];
    }
private:
	int m,n;
};