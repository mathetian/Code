/*class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        flag=false;
        if(s3.length()!=s1.length()+s2.length())
        	return false;
        if(s1.length()==0)
        {
        	if(s3==s2)
        		return true;
        	else
        		return false;
        }
        if(s2.length()==0)
        {
        	if(s3==s1)
        		return true;
        	else
        		return false;
        }
        len1=s1.size();len2=s2.size();len3=s3.size();
        this->s1=s1;this->s2=s2;this->s3=s3;
        dfs(0,0,0);
        return flag;
    }
private:
	bool flag;
	string s1,s2,s3;int len1,len2,len3;
	void dfs(int sz1,int sz2,int sz3)
	{
		if(flag==true)
			return;
		if(sz3==len3)
			flag=true;
		else
		{
			int a=sz1;int b=sz3;
			while(a<len1&&b<len3&&s1[a]==s3[b])
			{
				a++;b++;
			}
			if(b==len3)
			{
				flag=true;
				return;
			}
			for(int i=sz1;i<=a;i++)
			{
				int num1=i-sz1;
				int c=sz2;int d=sz3+num1;
				while(c<len2&&d<len3&&s2[c]==s3[d])
				{
					c++;d++;
				}
				if(c==sz2)
					continue;
				if(d==s3.length())
				{
					flag=true;
					return;
				}
				for(int j=sz2;j<c;j++)
				{
					int num2=j-sz2+1;
					dfs(sz1+num1,sz2+num2,sz3+num1+num2);
					if(flag==true)
						return;
				}
			}
		}
	}
};*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int len1=s1.size(),len2=s2.size(),len3=s3.size();
        if(len1+len2!=len3)
        	return false;
        int flag=true;
        vector<vector<int> >dp(len1+1,vector<int>(len2+1,0));
        dp[0][0]=1;

        for(int i=1;i<=len1;i++)
        {
        	if(s3[i-1]==s1[i-1]) dp[i][0]=1;
        	else break;
        }

        for(int i=1;i<=len2;i++)
        {
        	if(s3[i-1]==s2[i-1]) dp[0][i]=1;
        	else break;
        }

        for(int i=1;i<=len1;i++)
        {
        	for(int j=1;j<=len2;j++)
        	{
        		int k=i+j-1;
        		if(s3[k]==s1[i-1]||s3[k]==s2[j-1])
        		{
        			if(s3[k]==s1[i-1])
        				dp[i][j]|=dp[i-1][j];
        			if(s3[k]==s2[j-1])
        				dp[i][j]|=dp[i][j-1];
        		//	std::cout<<111<<endl;
        		}
        		else
        			dp[i][j]=0;
        		//std::cout<<dp[i][j]<<endl;
        	}
        }
        return dp[len1][len2];
    }
};

/*"ab", "bc", "bcab"
dp[i][0]=1
dp[0][j]=1
dp[1][1]=0
dp[1][2]=1
dp[2][1]=0
dp[2][2]|=dp[1][2]=1*/

int main()
{
	Solution solution;
	std::cout<<solution.isInterleave("ab","bc","bcab")<<std::endl;
	return 0;
}