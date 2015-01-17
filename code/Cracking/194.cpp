#include <iostream>
#include <vector>
using namespace std;

int max(int a,int b)
{
	int c=a-b;
	int k=(c>>31)&1;//1 a<b, 0 a>b
	return a-k*c; 
}