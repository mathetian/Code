#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include <stack>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char>s1;
        int i=0;
        while(i<s.size())
        {
        	if(s[i]==')'||s[i]==']'||s[i]=='}')
        	{
        		if(s1.empty())
        			return false;
                if(s[i]==')'&&s1.top()=='(')
                    s1.pop();
                else if(s[i]==']'&&s1.top()=='[')
                    s1.pop();
                else if(s[i]=='}'&&s1.top()=='{')
                    s1.pop();
        		else
        			return false;
        	}
        	else
        		s1.push(s[i]);
            i++;
        }
        if(s1.empty())
        	return true;
        return false;
    }
};

int main()
{
    string s="[]";
    Solution solution;
    std::cout<<solution.isValid(s)<<std::endl;
    return 0;
}