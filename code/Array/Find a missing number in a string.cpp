/**
	Question, https://sites.google.com/site/spaceofjameschen/home/string/find-a-missing-number-in-a-string----amazon

	Solution, http://stackoverflow.com/questions/19245137/find-the-missing-number-in-a-given-string
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

string itoa(int val)
{
	stringstream ss;
	ss<<val;
	return ss.str();
}

int atoi(string val)
{
	int result;
	stringstream(st) >> result;
	return result;
}

int findmissing(const string &str)
{
	int n=str.size();
	for(int i=1;i<n;i++)
	{
		string start=str.substr(0,i);
		int val=atoi(start);
		if（find
	}
}

void DoTest()
{
	int arr1[]={4, 6, 8, 3, 6};
	ASS_EQUAL(maxproduct(arr1, sizeof(arr1)/sizeof(int)), 288);
	int arr2[]={-3,-2,4,1,8};
	ASS_EQUAL(maxproduct(arr2, sizeof(arr2)/sizeof(int)), 48);
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;

	return 0;
}