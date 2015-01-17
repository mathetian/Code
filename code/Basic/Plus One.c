#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i=digits.size()-1;int carry=1;
        while(i>=0)
        {
        	digits[i]+=carry;
            //std::cout<<digits[i]<<endl;
        	if(digits[i]>=10)
        		carry=1;
            else
                carry=0;
        	digits[i]%=10;
            i--;
        }
        vector<int>rs;
        if(carry==1)
            rs.push_back(1);
        for(int i=0;i<digits.size();i++)
            rs.push_back(digits[i]);
        return rs;
    }
};

int main()
{
    Solution solution;
    vector<int> in;in.push_back(0);
    vector<int> out=solution.plusOne(in);
    for(int i=0;i<out.size();i++)
        std::cout<<out[i]<<endl;
    return 0;
}