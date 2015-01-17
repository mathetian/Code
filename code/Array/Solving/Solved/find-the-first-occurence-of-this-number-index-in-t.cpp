/**
	Question, https://sites.google.com/site/spaceofjameschen/home/search/find-the-first-occurence-of-this-number-index-in-this-array-without-using-linear-search-amazon
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

int find(int*arr,int n,int m)
{
	int i=0;while(i<n)
	{
		if(arr[i]==m) return i;
		i+=abs(m-arr[i]);
	}
	return -1;
}

void DoTest()
{
	int arr[]={4, 5, 6, 5, 6, 7, 8, 9, 10, 9, 1};
	ASS_EQUAL(find(arr, sizeof(arr)/sizeof(int), 2),-1);
	ASS_EQUAL(find(arr, sizeof(arr)/sizeof(int), 12),-1);
	ASS_EQUAL(find(arr, sizeof(arr)/sizeof(int), 7),5);
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;

	return 0;
}