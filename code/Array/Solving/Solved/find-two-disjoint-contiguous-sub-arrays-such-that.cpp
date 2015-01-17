/**
	Question, https://sites.google.com/site/spaceofjameschen/home/array/find-two-disjoint-contiguous-sub-arrays-such-that-the-absolute-difference

	Solution, http://cs.stackexchange.com/questions/13239/find-disjoint-contiguous-sub-arrays-in-better-than-mathcal-on2

	Similar problems exists in leetcode.
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

int maxsubarraytolerate(int*arr,int n)
{
	int rs=0;int end=0;
	for(int i=0;i<n;i++)
	{
		end=max(0,end+arr[i]);
		rs=max(end,rs);
	}
	return rs;
}

int maxsubarraynot(int*arr,int n)
{
	int rs=arr[0],end=arr[0];
	for(int i=1;i<n;i++)
	{
		end=max(arr[i],end+arr[i]);
		rs=max(end,rs);
	}

	return rs;
}

int findmxdiff(int*arr,int n)
{
	vector<int> mxl(n,0), mxr(n,0);
	vector<int> mnl(n,0), mnr(n,0);

	mxl[0]=arr[0];mnl[0]=arr[0];
	int end=arr[0],end2=arr[0];
	for(int i=1;i<n;i++)
	{
		end=max(arr[i],end+arr[i]);
		mxl[i]=max(end,mxl[i-1]);
		end2=min(arr[i],end2+arr[i]);
		mnl[i]=min(end2,mnl[i-1]);
	}
	mxr[n-1]=arr[n-1];mnr[n-1]=arr[n-1];
	end=end2=arr[n-1];
	for(int i=n-2;i>=0;i--)
	{
		end=max(arr[i],end+arr[i]);
		mxr[i]=max(end,mxr[i+1]);
		end2=min(arr[i],end2+arr[i]);
		mnr[i]=min(end2,mnr[i+1]);
	}

	int rs=0;
	for(int i=0;i<n-1;i++)
		rs=max(rs,max(mxr[i+1]-mnl[i],mxl[i]-mnr[i+1]));
	
	return rs;
}

void DoTest()
{
	int arr1[]={1, 2, 13, 15, 18};
	cout<<findmxdiff(arr1,sizeof(arr1)/sizeof(int))<<endl;
	int arr2[]={2, -1, -2, 1, -4, 2, 8};
	cout<<findmxdiff(arr2,sizeof(arr2)/sizeof(int))<<endl;
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;
	return 0;
}

