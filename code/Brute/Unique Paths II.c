/*class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
     m=obstacleGrid.size()-1;
     n=obstacleGrid[0].size()-1;
     k=0;
     if(obstacleGrid[0][0]==1)
      return k;
     flags=vector<vector<int> >(m+1,vector<int>(n+1,0));
     dfs(obstacleGrid,0,0);
     return k;
  }	
private:
	int m,n;
	int k;
  vector<vector<int> >flags;
  bool valid(int a,int b)
  {
    if(a>=0&&a<=m&&b>=0&&b<=n)
      return true;
    return false;
  }
  void dfs(vector<vector<int> >&obstacleGrid,int a,int b)
  {
    if(a==m&&b==n)
      k++;
    else
    {
      for(int i=a;i<m;i++)
      {
        if(obstacleGrid[i][b]==1)
          break;
        flags[i][b]=1;
      }

      for(int i=b;i<n;i++)
      {
        if(obstacleGrid[a][i]==1)
          break;
        flags[a][i]=1;
      }

      int nx=a, ny=b+1;
      if(valid(nx,ny)==true&&obstacleGrid[nx][ny]==0)
        dfs(obstacleGrid,nx,ny);
      nx=a+1;ny=b;
      if(valid(nx,ny)==true&&obstacleGrid[nx][ny]==0)
        dfs(obstacleGrid,nx,ny);
    }
  }
};*/

#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(obstacleGrid.size()==0)
          return 0;
        if(obstacleGrid[0][0]==1)
          return 0;

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> >dp(m, vector<int>(n, 0));
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
          for(int j=0;j<n;j++)
          {
            if(i==0&&j==0) continue;
            if(i==0) dp[i][j] = (obstacleGrid[i][j] == 1)?0:dp[i][j-1];
            else if(j==0) dp[i][j] = (obstacleGrid[i][j] == 1)?0:dp[i-1][j];
            else
              dp[i][j] = (obstacleGrid[i][j] == 1)?0:(dp[i-1][j]+dp[i][j-1]);
          }
        }
        return dp[m-1][n-1];
    }
};
