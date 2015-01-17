#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include <string.h>

class Solution {
public:
    string longestPalindrome(string s) 
    {
        int len=s.size();
        for(int i=0;i<len;i++) dp[i][0]=1;

        int longest=1; int beg = 0, len1 = 1;
        for(int d=2;d<=len;d++)
        {
            int r=len-d+1;
            for(int i=0;i<r;i++)
            {
                int j=i+d-1;
                dp[i][d-1] = 0;
                if(s[i]==s[j])
                {
                    if(i+1==j) dp[i][d-1]=1;
                    else dp[i][d-1]|=dp[i+1][d-3];
                }
                if(dp[i][d-1]==1 && d > longest)
                { beg = i; len1 = d; longest=d; }
            }
        }
        return s.substr(beg, len1);
    }
private:
    bool dp[1001][1001];
};

int main()
{
    Solution solution;
    string str = "aba";
    cout<<str.size()<<endl;
    std::cout<<solution.longestPalindrome(str)<<endl;
    return 0;
}