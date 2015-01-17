#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      if(x<0)
        return false;
      int base=1;
      while(x/base>=10)
        base*=10;
     // std::cout<<x/base<<std::endl;
      while(x!=0)
      {
        int a=x/base;
        int b=x%10;
       // std::cout<<a<<b<<std::endl;
        if(a!=b)
          return false;
        x=(x%base)/10;
        base/=100;
      }
      return true;
    }
};

int main()
{
  Solution solution;
  std::cout<<solution.isPalindrome(1001)<<std::endl;
  return 0;
}