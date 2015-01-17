/**
	https://sites.google.com/site/spaceofjameschen/home/array/find-min-diff-a-b-b-c-c-a----amazon
	How to solve it?

	Give a proof for the formual
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

int max3(int a,int b,int c)
{
	return max(a,max(b,c));
}

int min3(int a,int b,int c)
{
	return min(a,min(b,c));
}

int findmin(int*a,int*b,int*c,int na,int nb,int nc)
{
	int i=0,j=0,k=0;int rs=2*(max3(a[i],b[j],c[k])-min3(a[i],b[j],c[k]));
	while(i<na&&j<nb&&k<nc)
	{
		int a1=max3(a[i],b[j],c[k]);
		int b1=min3(a[i],b[j],c[k]);
		rs=min(rs,2*(a1-b1));
		if(a[i]==b1) i++;
		if(b[j]==b1) j++;
		if(c[k]==b1) k++;
	}
	return rs;
}

void DoTest()
{
	int arr1[]={1, 2, 13, 15, 18};
	int arr2[]={3, 5, 10, 12, 13};
	int arr3[]={2, 4, 6,  12, 13};
	ASS_EQUAL(findmin(arr1,arr2,arr3,sizeof(arr1)/sizeof(int),sizeof(arr2)/sizeof(int),sizeof(arr3)/sizeof(int)),0);

	int arr4[]={1};
	int arr5[]={7, 10, 12, 13};
	int arr6[]={2, 4, 6,  12, 13};
	ASS_EQUAL(findmin(arr4,arr5,arr6,sizeof(arr4)/sizeof(int),sizeof(arr5)/sizeof(int),sizeof(arr6)/sizeof(int)),12);
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;
	return 0;
}


