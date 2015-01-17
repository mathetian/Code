/**
	Question, https://sites.google.com/site/spaceofjameschen/home/number-and-string/find-nth-largest-element-in-an-array-of-m-elements-where-n--0-n-is-much-smaller-than-m-without-sorting

	There are many solution for it. When m<<n, there is a very good solution.
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

void heapify(int*arr,int n,int index)
{
	int l=index*2+1,r=index*2+2;
	if(l>=n) return;

	if(r>=n)
	{
		if(arr[index]>arr[l])
			swap(arr[index],arr[l]);
	}
	else
	{
		int m=min(arr[l],arr[r]);
		if(m<arr[index])
		{
			if(m==arr[l])
			{
				swap(arr[index],arr[l]);
				heapify(arr,n,l);
			}
			else
			{
				swap(arr[index],arr[r]);
				heapify(arr,n,r);
			}
		}
	}
}

void buildheap(int*arr,int n)
{
	for(int i=n/2-1;i>=0;i--)
		heapify(arr,n,i);
}

int find(int*arr,int n,int m)
{
	buildheap(arr,n);
	for(int i=0;i<m;i++)
	{
		swap(arr[0],arr[n-1-i]);
		heapify(arr,n-1-i,0);
	}
	return arr[n-m];
}

void DoTest()
{
	int arr[]={20, 46, 7, 63, 22, 25, 31, 30, 30, 74};
	ASS_EQUAL(find(arr, sizeof(arr)/sizeof(int), 1),7);
	ASS_EQUAL(find(arr, sizeof(arr)/sizeof(int), 5),30);
	ASS_EQUAL(find(arr, sizeof(arr)/sizeof(int), 10),74);
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;

	return 0;
}