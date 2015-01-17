#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size()==0)
        	return 1;
        char result[1000];int j=0;
        for(int i=0;i<s.size();i++)
        {
        	char t1=s[i];
        	if(t1>='a'&&t1<='z')
  				result[j++]=t1;
  			if(t1>='A'&&t1<='Z')
  				result[j++]=t1+'a'-'A';
  			if(t1>='1'&&t1<='9')
  				result[j++]=t1;
        }
        for(int i=0;i<j/2;i++)
        {
        	if(result[i]!=result[j-1-i])
        		return 0;
        }
        return 1;
    }
};

bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.length()==0)
          return 1;
        string result;int j=0;
        for(int i=0;i<s.length();i++)
        {
          char t1=s[i];
          if(t1>='a'&&t1<='z')
          result[j++]=t1;
        if(t1>='A'&&t1<='Z')
          result[j++]=t1+'a'-'A';
        if(t1>='1'&&t1<='9')
          result[j++]=t1;
        }
        for(int i=0;i<j/2;i++)
        {
          if(result[i]!=result[j-1-i])
            return 0;
        }
        return 1;
}

int main()
{
  Solution solution;
  std::cout<<solution.isPalindrome("aA")<<endl;
  return 0;
}