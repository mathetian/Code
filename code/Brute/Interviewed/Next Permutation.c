#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len=num.size();
        int i;
        for(i=len-1;i>=1;i--)
        {
        	//4 5
        	if(num[i-1]<num[i])
        		break;
        }
        if(i==0)
        {
             std::reverse(num.begin(),num.end());
             return;
        }
        	
        //i-1
      
        std::reverse(num.begin()+i,num.end());
        // std::cout<<num[0]<<num[1]<<num[2]<<endl;
        int j;
        for(j=i;j<len;j++)
        {
            if(num[j]>num[i-1])
                break;
        }
        int tmp=num[i-1];
        num[i-1]=num[j];
        num[j]=tmp;
        return;
    }
};

int main()
{
    Solution solution;
    vector<int>num;
    num.push_back(2);num.push_back(3);num.push_back(1);
    solution.nextPermutation(num);
    std::cout<<num[0]<<num[1]<<num[2]<<endl;
    return 0;
}