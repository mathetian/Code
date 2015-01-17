#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==1)
        	return "1";
        if(n==2)
        	return "11";
       	string cur="1";
       	for(int i=1;i<n;i++)
       	{
       		int j=0;string cur2="";
       		while(j<cur.size())
       		{
       			int k=j+1;
       			while(k<cur.size()&&cur[k]==cur[j])
       				k++;
       			int tim=k-j;
       			string t1="";
       			while(tim!=0)
       			{
       				t1.insert(0,1,'0'+tim%10);
              tim=tim/10;
       			}
            t1.push_back(cur[j]);		
       			cur2+=t1;
       			j=k;
       		}
       		cur=cur2;	
       	}
       	return cur;
    }
};

int main()
{
  Solution solution;
  std::cout<<solution.countAndSay(3)<<endl;
  return 0;
}