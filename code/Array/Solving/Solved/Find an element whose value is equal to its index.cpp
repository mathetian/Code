/**
	Question, https://sites.google.com/site/spaceofjameschen/home/search/find-the-element-whose-value-is-equal-to-its-index
**/

#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

int findelement(int*arr,int n)
{
	int l=0,r=n-1;
	while(l<=r)
	{
		int m=(l+r)>>1;
		if(arr[m]-m==0) return m;
		else if(arr[m]-m>0) r=m-1;
		else l=m+1;
	}
	return -1;
}

void DoTest()
{
	int arr1[]={-3,0,1,3,6,7,8,11,12,13,14,15,16};
	ASS_EQUAL(findelement(arr1,sizeof(arr1)/sizeof(int)), 3);
	int arr2[]={3,4,6,7,8,11,12,13,14,15,16};
	ASS_EQUAL(findelement(arr2,sizeof(arr2)/sizeof(int)), -1);
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;

	return 0;
}