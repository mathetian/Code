/**
	Guess some bugs in the solution.

	Question, https://sites.google.com/site/spaceofjameschen/home/number-and-string/given-an-integer-n-print-numbers-from-1-to-n-in-lexicographic-order----bloomberg-lp
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

void print(int cur,int n)
{
	cout<<cur<<endl;
	for(int i=0;i<10;i++)
	{
		int cur2=cur*10+i;
		if(cur2>n) break;
		print(cur2, n);
	}
}

void print(int n)
{
	for(int i=1;i<10;i++)
	{
		print(i,n);
	}
}

void DoTest()
{
	print(12);
	cout<<endl;
	print(80);
}

int main()
{
	DoTest();

	cout<<"Passed All Test"<<endl;
	return 0;
}
