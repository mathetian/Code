#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) 
    {
		stack<int> cstk;
		int mxl=0, l=-1;
		for(int i=0;i<s.size();i++)
		{
			if(s.at(i)=='(') cstk.push(i);
			else
			{
				if(cstk.empty() == true) l = i;
				else
				{
					cstk.pop();
					if(cstk.empty()) mxl = max(mxl, i-l);
					else mxl=max(mxl,i-cstk.top());
				}
 			}
		} 
		return mxl;   	    
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int n = s.size();
        int max_valid = 0;
        int count_left = 0, valid_count = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                count_left += 1;
                valid_count += 1;
            }
            else {
                valid_count -= 1;
            }
            
            if (valid_count < 0) {
                valid_count = 0;
                count_left = 0;
            }
            else if (valid_count == 0) {
                max_valid = max(max_valid, count_left);
            }
        }
        
        valid_count = 0;
        int count_right = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')') {
                count_right += 1;
                valid_count += 1;
            }
            else {
                valid_count -= 1;
            }
            
            if (valid_count < 0) {
                valid_count = 0;
                count_right = 0;
            }
            else if (valid_count == 0) {
                max_valid = max(max_valid, count_right);
            }
        }
        return 2 * max_valid;
    }
};