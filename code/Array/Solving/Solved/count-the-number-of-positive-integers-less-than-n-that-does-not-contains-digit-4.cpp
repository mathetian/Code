/**
	Question, https://sites.google.com/site/spaceofjameschen/home/number-and-string/count-the-number-of-positive-integers-less-than-n-that-does-not-contains-digit-4----google
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

bool exist4(string str)
{
	int index=str.find('4');
	return index==-1?0:1;
}

string itoa(int val)
{
	stringstream ss;
	ss<<val; return ss.str();
}

int count(int n)
{
	int rs=0;
	for(int i=0;i<=n;i++){
		rs+=exist4(itoa(i));
	}
	cout<<rs<<endl;
	return rs;
}

void DoTest()
{
	ASS_EQUAL(count(9494), (9494-6155));
	ASS_EQUAL(count(9495), (9495-6155));
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;
	return 0;
}