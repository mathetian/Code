#include <vector>
#include <string>
#include <iostream>
using namespace std;

int c(char d)
{
	return d=='c'?1:0;
}

int calc(string const &str) {
	int a=0;int i,j;
	for(i=0;i<str.size();i++) a=a+c(str.at(i));
    if(a%2==1) return 0;a/=2;
	if(a==0) return str.size()-1;
	for(i=0,j=0;i<str.size();i++)
	{
		if(c(str.at(i))==1) j++;
		if(j==a) break;
	}
	int k=i+1;
	while(k<str.size()&&c(str.at(k))==0) k++;
	return k-i;
}