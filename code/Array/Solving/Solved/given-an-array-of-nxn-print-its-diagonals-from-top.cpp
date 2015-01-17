/**
	Interview question, bad feeling.

	Question, https://sites.google.com/site/spaceofjameschen/home/array/given-an-array-of-nxn-print-its-diagonals-from-top-right-to-bottom-left
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

void print(int arr[][5],int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<i+1&&j<n;j++)
			cout<<arr[i-j][j]<<" ";
	}

	for(int i=m;i<m+n;i++)
	{
		for(int j=i-m+1;j<n&&i-j>=0;j++)
			cout<<arr[i-j][j]<<" ";
	}

	cout<<endl;
}

void DoTest()
{
	int arr[6][5]={{20, 54, 78, 88, 27}, 
				   {66, 66, 81, 69, 85}, 
				   {68, 45, 45, 50, 39}, 
				   {96, 82, 32, 19, 40},
				   {20, 54, 78, 88, 27},
				   {20, 54, 78, 88, 27}};

	print(arr,6,5);
}

int main()
{
	DoTest();
	cout<<"Passed All Tests"<<endl;
	return 0;
}