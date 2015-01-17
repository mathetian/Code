#include <string>
#include <iostream>
using namespace std;

int sameonenext(int a)
{
	int i=0,j,b=a;int count=1;
	while((b&1)==0) {i++;b>>=1;} 
	b>>=1;j=i+1;while((b&1)==1) {j++;b>>=1;count++;}
	a|=(1<<j); a|=((1<<(count+1))-1);
	return a;
}

int sameoneprev(int a)
{
	int i=0,j,b=a;
	while((b&1)==1) {i++;b>>=1;}
	b>>=1;j=i+1;while((b&1)==0) {j++;b>>=1;}
	a&=(~(1<<j)); a|=((1<<(j-i))-1);
}

int main()
{
	return 0;
}