#include <iostream>
#include <vector>
using namespace std;

int add(int a,int b)
{
	if(b==0) return a;
	int c=a^b, d=(a&b)<<1;
	return add(c,d);
}