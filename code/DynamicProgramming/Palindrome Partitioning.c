#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len=s.size();
        vector<vector<int> >dp(len+1,vector<int>(len+1,0));
        for(int i=0;i<len;i++)
        	dp[i][i]=1,dp[i+1][i]=1;
        for(int d=2;d<=len;d++)
        {
        	for(int i=0;i<len;i++)
        	{
        		int j=i+d-1;
        		if(j>=len)
        			break;

        		if(s[i]==s[j])
        			dp[i][j]|=dp[i+1][j-1];
        		else
        			dp[i][j]=0;
        	}
        }
        //std::cout<<dp[0][1]<<endl;
        vector<vector<string> >rs;
        vector<string>tmp;
        this->s=s;
        this->len=len;
        dfs(rs,0,dp,tmp);
        return rs;
    }
private:
	string s;int len;
	void dfs(vector<vector<string> >&rs,int pos,vector<vector<int> >dp,vector<string>tmp)
	{
		if(pos==len)
			rs.push_back(tmp);
		else
		{
			for(int i=pos;i<len;i++)
			{
				if(dp[pos][i]==0)
					continue;
				tmp.push_back(s.substr(pos,i-pos+1));
				dfs(rs,i+1,dp,tmp);
				tmp.pop_back();
			}
		}
	}
};

int main()
{
    Solution solution;
    vector<vector<string> >rs=solution.partition("bb");
    for(int i=0;i<rs.size();i++)
    {
        for(int j=0;j<rs[i].size();j++)
            std::cout<<rs[i][j]<<endl;
    }
    return 0;
}