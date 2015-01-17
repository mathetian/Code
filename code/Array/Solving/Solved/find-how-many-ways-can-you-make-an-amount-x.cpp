/**
	Question, https://sites.google.com/site/spaceofjameschen/home/c-1/find-how-many-ways-can-you-make-an-amount-x----microsoft

	Specifically, use iteration instead of recursive
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

int countAll(int n)
{
	int rs=0;
	for(int i=0;i<=n/10;i++)
	{
		for(int j=0;j<=n/5;j++)
		{
			for(int k=0;k<=n/2;k++)
			{
				if(i*10+j*5+k*2>n) break;
				rs++; 
			}
		}
	}
	return rs;
}

void DoTest()
{
	ASS_EQUAL(countAll(0),1);
	ASS_EQUAL(countAll(3),2);
	ASS_EQUAL(countAll(5),4);
	ASS_EQUAL(countAll(15),22);
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;
	return 0;
}