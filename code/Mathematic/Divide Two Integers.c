#include <algorithm>
#include <iostream>
using namespace std;

#include <assert.h>

class Solution {
public:
    int divide(int d1, int d2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      int flag=0;
      uint64 dividend = d1, divisor = d2;
      if((divisor>0&&dividend>0)||(divisor<0&&dividend<0))
        flag=1;
      else flag=-1;

      dividend=max(dividend,-dividend);
      divisor=max(divisor,-divisor);
      if(dividend==0) return 0;
     return flag*unsig(dividend,divisor);
    }

private:
  typedef long long uint64;
  int unsig(uint64 dividend, uint64 divisor)
  {
    uint64 num = divisor; uint64 count=0;uint64 rs=0;
    while(num < dividend) { count++;num<<=1; }
    if(num == dividend) { rs = 1<<count; return rs; }
    if(count == 0) { return 0; }
    count--; rs |= (1<<count);
    num = (divisor<<count);
    dividend-=num;
    //cout<<num<<" "<<dividend<<" "<<rs<<endl;
    while(dividend>0 && num >= divisor)
    {
      while(num > dividend && num> 0) { num>>=1; count--; }
      if(num < divisor) break;
      dividend -= num;
      rs |= (1ull<<count);
      //cout<<num<<" "<<dividend<<" "<<rs<<" "<<count<<endl;
    }
    return rs;
  }
};

int main()
{
  Solution sol;
  cout<<sol.divide(-15, 3)<<endl;
  return 0;
}