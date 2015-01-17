/**
	Question, https://sites.google.com/site/spaceofjameschen/home/sort-and-search/three-ways-sorting---yahoo

	Quicksort
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

void threewaysort(int*arr,int n,int k)
{
	int i,j;for(i=0;i<n&&arr[i]!=k;i++);
	if(i==n) return;
	
	swap(arr[i],arr[n-1]);
	for(i=0,j=0;i<n-1;i++)
	{
		if(arr[i]<k)
		{
			swap(arr[i],arr[j]); j++;
		}
	}
	swap(arr[j],arr[n-1]);
}


void DoTest()
{
	int arr1[]={3, 1, 2, 5, 7, 8, 4, 0, 9, 6};
	int arr2[]={3, 1, 2, 5, 7, 8, 4, 0, 9, 6};

	int n=sizeof(arr1)/sizeof(int);
	threewaysort(arr1, n, 10);
	for(int i=0;i<n;i++)
		ASS_EQUAL(arr1[i],arr2[i]);

	threewaysort(arr1, n, 4);
	for(int i=0;i<n;i++)
		cout<<arr1[i]<<" ";
	cout<<endl;
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;

	return 0;
}