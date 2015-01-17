/**
	Solve it in time complexity, O(n)
	https://sites.google.com/site/spaceofjameschen/home/array/find-the-longest-subset-with-consecutive-numbers----google
	http://stackoverflow.com/questions/7683077/find-the-largest-subset-of-it-which-form-a-sequence
**/
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

void findTheLongest(int*arr, int n)
{
	int mn=arr[0],mx=arr[0];
	for(int i=0;i<n;i++)
	{
		mn=min(mn,arr[i]);
		mx=max(mx,arr[i]);
	}
	
	vector<int>table(mx-mn+1,-1);
	for(int i=0;i<n;i++)
	{
		if(table[arr[i]-mn]==-1)
			table[arr[i]-mn]=i;
	}

	int rs=0,st=0;int i=0, tmp=-1;
	for(;i<mx-mn+1;i++)
	{
		if(table[i]!=-1)
		{ if(tmp==-1) tmp=i; }
		else
		{
			if(tmp!=-1)
			{
				if(rs<i-tmp)
				{ rs=i-tmp;st=tmp;}
			}
			tmp=-1;
		}
	}

	if(tmp!=-1)
	{
		if(rs<i-tmp)
		{
			rs=i-tmp;st=tmp;
		}
	}
	for(int i=0;i<rs;i++)
		cout<<st+i+mn<<" ";
	cout<<endl;
}

void DoTest()
{
	int arr[]= { 5, 1, 9, 3, 8, 20, 4, 10, 2, 11, 3} ;
	findTheLongest(arr, sizeof(arr)/sizeof(int));
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;

	return 0;
}