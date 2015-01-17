#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

/*class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        num=0;
        if(s.size()==0)
        	return num;
       	dfs(s,0);
       	return num;
    }
private:
	int num;
	void dfs(string s,int index)
	{
		if(index==s.size())
			num++;
		else
		{
			if(s[index]>='3')
				dfs(s,index+1);
			else if(s[index]=='0')
				return;
			else
			{
				dfs(s,index+1);
				if(index+1<s.size())
				{
					if(s[index]=='1')
						dfs(s,index+2);
					else
					{
						if(s[index+1]>'6')
							return;
						dfs(s,index+2);
					}
				}
			}
		}
	}
};*/


class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size()==0)
        	return 0;
        if(s.size()==1)
        {
        	if(s.at(0)=='0')
        		return 0;
        	return 1;
        }
        if(s.at(0)=='0')
        	return 0;
        vector<int>dp;
        dp.push_back(1);dp.push_back(1);
		for(int i=1;i<s.size();i++)
		{
			if(s.at(i)=='0')
			{	
				if(s.at(i-1)=='0')
				{
					//impossible
					dp.push_back(0);
				}
				else if(s.at(i-1)>='3')
				{
					//impossible
					dp.push_back(0);
				}
				else
					dp.push_back(dp[i-1]);
			}
			else if(s.at(i)>='3')
			{
				if(s.at(i-1)>='3'||s.at(i-1)=='0')
					dp.push_back(dp[i]);
				else if(s.at(i-1)=='2')
				{
					if(s.at(i)>='7')
						dp.push_back(dp[i]);
					else
						dp.push_back(dp[i]+dp[i-1]);
				}
				else
					dp.push_back(dp[i]+dp[i-1]);
			}
			else
			{
				if(s.at(i-1)>='3'||s.at(i-1)=='0')
					dp.push_back(dp[i]);
				else
					dp.push_back(dp[i]+dp[i-1]);
			}
		}       
		return dp.at(s.size()); 
    }
};

int main()
{
	//std::string s="4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948";
	std::string s="00";
	Solution solution;
	std::cout<<solution.numDecodings(s)<<endl;
}