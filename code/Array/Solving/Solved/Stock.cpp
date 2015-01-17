/**
	There are three similar problem in Leetcode and there are many solution for it. Mathematic and Dynamic Programming.

	The second problem in leetcode,
	https://sites.google.com/site/spaceofjameschen/home/array/find-max-benefit-in-best-time-complexity----amazon
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

int stock1(vector<int>&arr1)
{
	int n=arr1.size(); 
	vector<int>mn(n,0), mx(n,0);
	mn[0]=arr1.at(0);mx[n-1]=arr1.at(n-1);
	for(int i=1;i<n;i++)
		mn[i]=min(arr1.at(i),mn[i-1]);
	for(int i=n-2;i>=0;i--)
		mx[i]=max(arr1.at(i),mx[i+1]);
	int rs=0;
	for(int i=0;i<n;i++)
		rs=max(rs,mx[i]-mn[i]);
	return rs;
}

int stock2(vector<int>&arr2)
{
	int rs=0;
	for(int i=1;i<arr2.size();i++)
	{
		if(arr2.at(i)-arr2.at(i-1)>0)
			rs+=arr2.at(i)-arr2.at(i-1);
	}
	return rs;
}

int stock3(vector<int>&arr3)
{
	int n=arr3.size();
	vector<vector<int> >dp(2,vector<int>(n,0));
	int mnval=arr3.at(0),mxpro=0;
	for(int i=0;i<n;i++)
	{
		mnval=min(mnval,arr3.at(i));
		mxpro=max(mxpro,arr3.at(i)-mnval);
		dp[0][i]=mxpro;
	}
	int mxval=arr3.at(n-1);mxpro=0;
	for(int i=n-1;i>=0;i--)
	{
		mxval=max(mxval,arr3.at(i));
		mxpro=max(mxpro,mxval-arr3.at(i));
		dp[1][i]=mxpro;
	}	
	int rs=0;
	for(int i=0;i<n;i++)
		rs=max(rs,dp[0][i]+dp[1][i]);
	return rs;
}

void DoTest()
{
	int arr[]={5, 1, 4 ,6 ,7 ,8 ,4 ,3 ,7 ,9, 8};
	vector<int>arrv(arr,arr+sizeof(arr)/sizeof(int));
	ASS_EQUAL(stock1(arrv),8);
	ASS_EQUAL(stock2(arrv),13);
	ASS_EQUAL(stock3(arrv),13);
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;

	return 0;
}