#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int>allBits;
        if(n==0)
        	return 1;
        int m=max(n,-n);
        while(m>=1)
        {
        	allBits.push_back(m&1);
        	m=m>>1;
        }
        std::reverse(allBits.begin(),allBits.end());
        double r=1;int r1=0;
        for(int i=0;i<allBits.size();i++)
        {
        	r=r*r;
        	if(allBits[i]==1)
        		r=r*x;
        }
        if(n<0)
        	r=1.0/r;
        return r;
    }

    double pow2(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double result = 1.0;
        bool negative = false;
        if (n < 0) negative = true;
        while (n) {
            if (n & 1)
                result *= x;
            x *= x;
            n /= 2;
        }
        return negative ? (1.0 / result) : result;
    }
};

int main()
{
    Solution solution;
    std::cout<<solution.pow(1.12330,24)<<std::endl;
}