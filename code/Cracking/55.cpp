#include <string>
#include <iostream>
using namespace std;

int change(int a,int b)
{
	int c=a^b,d=0;
	for(;c!=0;c>>=1)
	{ if((c&1)==1) d++; }
	return d;
}