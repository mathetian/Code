#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 2010;
const int INFS = 0x3fffffff;

class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //dynimical programming

        //dp[i][j]={dp[i][j],dp[i+1][j-1]+1}

        int len=s.size();
       	vector<vector<int> >dp(len+1,vector<int>(len+1,0));
       	for(int i=0;i<len;i++)
       		dp[i][i]=1,dp[i+1][i]=1;
       	for(int d=1;d<len;d++)
       	{
       		for(int i=0;i<len;i++)
       		{
            //i i+d
       			if(i+d>=len)
       				break;
       			if(s[i]==s[i+d])
       				dp[i][i+d]|=dp[i+1][i+d-1];
       			else
       				dp[i][i+d]=0;
       		}
       	}
       	vector<int>F(len,INFS);
       	F[0]=0;
       	for(int i=1;i<len;i++)
       	{
       		if(dp[0][i]==1)
            F[i]=0;
          else
          {
            for(int j=1;j<=i;j++)
            {
              if(dp[j][i]==1)
                F[i]=min(F[j-1]+1,F[i]);
            }
          }
       	}
       	return F[len-1];
    }
};

int main()
{
  Solution solution;
  std::cout<<solution.minCut("bb")<<std::endl;
  return 0;
}