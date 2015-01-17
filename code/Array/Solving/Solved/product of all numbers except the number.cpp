/**
	Question, https://sites.google.com/site/spaceofjameschen/home/array/fill-the-array-with-product-of-all-numbers-except-the-number-in-that-cell----google

	Better explanation,
	http://stackoverflow.com/questions/2680548/given-an-array-of-numbers-return-array-of-products-of-all-other-numbers-no-div

	Solution, use two arrays and each array can be computed in linear time. At the same time, it needs linear space.

	Another solution, use GCF(great common factor) instead.
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

void product(int*arr,int n)
{
	vector<int> l(n,1), r(n,1);

	int i=1;for(;i<n;i++)
		l[i]=l[i-1]*arr[i-1];
	i=n-2;for(;i>=0;i--)
		r[i]=r[i+1]*arr[i+1];
	for(i=0;i<n;i++)
		arr[i]=l[i]*r[i];
}	

void DoTest()
{
	int arr[]={5, 6, 3, 6, 2, 2, 1, 6, 5, 9};
	int arr2[]={5, 6, 3, 6, 2, 2, 1, 6, 5, 9};
	int n=sizeof(arr)/sizeof(int);
	product(arr, n); vector<int>ans(n,0);
	for(int i=0;i<n;i++)
	{
		int rs=1;
		for(int j=0;j<i;j++) rs*=arr2[j];
		for(int k=i+1;k<n;k++) rs*=arr2[k];
		ans[i]=rs;
	}

	for(int i=0;i<n;i++)
		ASS_EQUAL(ans[i],arr[i]);
}

int main()
{
	DoTest();
	cout<<"Passed All Tests"<<endl;
	return 0;
}