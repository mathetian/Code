/**
	Question, https://sites.google.com/site/spaceofjameschen/home/array/find-the-maxproduct-of-three-numbers-from-a-given-integer-array----amazon
	Solution, http://crackprogramming.blogspot.com/2012/11/given-array-of-integers-return-maximum.html

	Bad feeling. A very simple solution for it.
**/

//Edge situation
// int maxproduct(int*arr,int n)
// {
// 	int mx2=1,mn2=1,mx1=1,mn1=1;int rs=1;
// 	mx1=arr[0]>0?arr[0]:mx1;
// 	mn1=arr[0]<0?arr[0]:mn1;

// 	if(arr[1]>0)
// 	{
// 		mx1=max(mx1,arr[1]);
// 	}
// }

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

int maxproduct(int*arr,int n)
{
	if(n<3) return -1;
	sort(arr,arr+n);
	int val1=arr[n-1]*arr[n-2]*arr[n-3];
	int val2=arr[n-1]*arr[0]*arr[1];
	return val1<val2?val2:val1;
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

