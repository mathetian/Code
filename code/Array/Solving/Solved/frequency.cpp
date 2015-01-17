/**
	Aslo, the first missing value in the array
	https://sites.google.com/site/spaceofjameschen/home/array/compute-the-frequency-of-each-element-in-an-array
	Another question,
	Find the first missing value in the sorted array
	http://stackoverflow.com/questions/11385896/find-the-first-missing-number-in-a-sorted-list
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

void frequency(int*arr,int n)
{
	for(int pos=0;pos<n;)
	{
		int epos=arr[pos]-1;
		if(arr[pos]>0&&arr[epos]>0)
		{
			swap(arr[pos],arr[epos]);
			arr[epos]=-1;
		}
		else if(arr[pos]>0)
		{
			arr[epos]--;
			arr[pos++]=0;
		}
		else pos++;
	}

	for(int pos=0;pos<n;pos++)
		arr[pos]=-arr[pos];
}

int findfirstmssing(int*arr,int n)
{
	int i=n-1,j=i;
	while(i>=0)
	{
		if(arr[i]<=0) { swap(arr[i],arr[j]); j--; }
		i--;
	}

	n=j+1;i=0;
	while(i<n)
	{
		if(arr[i]==i+1) i++;
		else
		{
			j=arr[i]-1;
			if(arr[j]!=j+1)
				swap(arr[i],arr[j]);
			else i++;
		} 
	}

	for(i=0;i<n&&arr[i]==i+1;i++);
	if(i<n) return i+1;
	return 0;
}

int stackoverflow(int*arr,int n)
{
	return 0;
}

void DoTest1()
{
	int arr1[]={ 1,  3,  5,  7,  9,  1,  3,  5,  7,  9,  1, 2};
	frequency(arr1, sizeof(arr1)/sizeof(int));
	for(int i=0;i<sizeof(arr1)/sizeof(int);i++)
		cout<<i+1<<" "<<arr1[i]<<endl;
}

void DoTest2()
{
	int arr1[]={ 1,  3,  5,  7,  9,  1,  3,  5,  7,  9,  1, 2};
	ASS_EQUAL(findfirstmssing(arr1, sizeof(arr1)/sizeof(int)), 4);
	int arr2[]={0, 1,  -3,  5, -7,  9,  1,  3,  -5,  7,  9,  1, 2, 4};
	ASS_EQUAL(findfirstmssing(arr2, sizeof(arr2)/sizeof(int)), 6);
}

int main()
{
	DoTest1();DoTest2();
	cout<<"Passed All Test"<<endl;
	
	return 0;
}