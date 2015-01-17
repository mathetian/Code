/**
	https://sites.google.com/site/spaceofjameschen/home/array/sort-array-without-second-loop

	There are many similar problems.
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

void sort(int*arr,int n)
{
	int i=0;while(i<n)
	{
		if(arr[i]==i) i++;
		else
			swap(arr[i],arr[arr[i]]);
	}
}

void DoTest()
{
	int arr[]={3, 1, 2, 5, 7, 8, 4, 0, 9, 6};
	sort(arr, sizeof(arr)/sizeof(int));
	int sarr[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
		ASS_EQUAL(arr[i],sarr[i]);
}

int main()
{
	DoTest();
	cout<<"Passed All Tests"<<endl;
	return 0;
}