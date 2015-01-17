#include <vector>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l1=strlen(s);int l2=strlen(p);
        vector<vector<int> >dp   (l1+1,vector<int>(l2+1,0));
        vector<vector<int> >left (l1+1,vector<int>(l2+1,0));
        vector<vector<int> >right(l1+1,vector<int>(l2+1,0));

        dp[0][0]=1;
        int i,j;
        for(i=1;i<=l1;i++)
        {
        	if(s[i-1]!='*') break;
        	dp[i][0]=1; left[i][0]=1;
        }
        j=i;
        while(j<=l1)
        {
        	left[j][0]=i-1; j++;
        }

        for(i=1;i<=l2;i++)
        {
        	if(p[i-1]!='*')	break;
        	dp[0][i]=1;
        }
        j=i;
        while(j<=l2)
        {
        	right[0][j]=i-1; j++;
        }

        for(i=1;i<=l1;i++)
        {
        	for(j=1;j<=l2;j++)
        	{
        		int vs=getF(s[i-1]),vp=getF(p[j-1]);
        		
				if((vs==2&&vp==2)||(vs==0&&vp==0))
				{
					if(s[i-1]==p[j-1])
						dp[i][j]|=dp[i-1][j-1];
					if(dp[i][j]==0)
					{
						left[i][j]=left[i-1][j];
					}
				}
				else if(vs==2&&vp==1)
				{
					dp[i][j]|=dp[i][j-1];
					if(dp[i][j]==0)
					{
						int pos1=left[i][j-1];
						dp[i][j]|=dp[pos1][j-1];
					}
				}
				else if((vs==2&&vp==0)||(vs==0&&vp==2))
					dp[i][j]|=dp[i-1][j-1];
				else if(vs==1&&vp==2)
				{
					dp[i][j]|=dp[i-1][j];
					if(dp[i][j]==0)
					{
						int pos1=right[i-1][j];
						dp[i][j]|=dp[i-1][pos1];
					}
				}
				else if(vs==1&&vp==1)
				{
					dp[i][j]|=dp[i][j-1];
					if(dp[i][j]==0)
					{
						int pos1=left[i][j-1];
						dp[i][j]|=dp[pos1][j-1];
					}

					dp[i][j]|=dp[i-1][j];
					if(dp[i][j]==0)
					{
						int pos1=right[i-1][j];
						dp[i][j]|=dp[i-1][pos1];
					}
				}
				else if(vs==1&&vp==0)
				{
					dp[i][j]|=dp[i][j-1];
					if(dp[i][j]==0)
					{
						int pos1=left[i][j-1];
						dp[i][j]|=dp[pos1][j-1];
					}
				}
				else if(vs==0&&vp==1)
				{
					dp[i][j]|=dp[i-1][j];
					if(dp[i][j]==0)
					{
						int pos1=right[i-1][j];
						dp[i][j]|=dp[i-1][pos1];
					}
				}
        	}
        }

        for(int i=0;i<=l1;i++)
        {
        	for(int j=0;j<=l2;j++)
        	{
        		std::cout<<i<<" "<<j<<":"<<dp[i][j]<<endl;
        	}
        }
        return dp[l1][l2];
    }
private:
	int getF(char v)
	{
		if(v=='?')
			return 0;
		if(v=='*')
			return 1;
		return 2;
	}
};

int main()
{
	Solution solution;
	cout<<solution.isMatch("aa", "a*")<<endl;
	return 0;
}