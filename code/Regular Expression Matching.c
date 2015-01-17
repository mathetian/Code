#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
       	this->s=s;this->p=p;
       	l1=strlen(s); l2=strlen(p);
       	flag=0;dfs(l1-1,l2-1);
    	return flag;
    }
private:
	const char*s;const char*p;
	int l1,l2;bool flag;
	int getF(char f)
	{
		if(f=='.')
			return 0;
		if(f=='*')
			return 1;
		return 2;
	}
	void dfs(int a,int b)
	{
		if(flag==true)
			return;
		if(a==-1||b==-1)
		{
			if(a==-1&&b==-1)
				flag=true;
			else if(a==-1)
			{
				string p1(p,p+b+1);
				string p2(b+1,'*');
				if(p1==p2)
					flag=true;
			}	
			else if(b==-1)
			{
				string p1(s,s+a+1);
				string p2(a+1,'*');
				if(p1==p2)
					flag=true;
			}
			return;
		}
		int f1=getF(s[a]),f2=getF(p[b]);
		if((f1==2&&f2==2)||(f1==0&&f2==0))
		{
			if(s[a]==p[b])
				dfs(a-1,b-1);
		}
		else if((f1==2&&f2==0)||(f1==0&&f2==2)||(f1==0&&f2==0))
			dfs(a-1,b-1);
		else if((f1==2&&f2==1)||(f1==0&&f2==1))
		{
			for(int j=b-1;flag==false&&j>=-1;j--)
				dfs(a, j);
		}
		else if((f1==1&&f2==0)||(f1==1&&f2==2))
		{
			for(int j=a-1;flag==false&&j>=-1;j--)
				dfs(j, b);
		}
		else
		{
			dfs(a-1, b); dfs(a, b-1);
			for(int i=a-1;flag==false&&i>=-1;i--)
				for(int j=b-1;flag==false&&j>=-1;j--)
					dfs(i,j);
		}
	}
};

int main()
{
	Solution solution;
	std::cout<<solution.isMatch("aab","c*a*b")<<endl;
}