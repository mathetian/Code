/**
	Question, https://sites.google.com/site/spaceofjameschen/home/tree/find-the-maximum-j---i-such-that-a-j-a-i
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

int findmx(int*arr,int n)
{
	vector<int> lmx(n,0);
	vector<int> rmn(n,0);
	lmx[0]=arr[0];rmn[n-1]=arr[n-1];
	for(int i=1;i<n;i++)
		lmx[i]=max(arr[i],lmx[i-1]);
	for(int i=n-2;i>=0;i--)
		rmn[i]=max(arr[i],rmn[i+1]);
	int i=0,j=0;int rs=0;
	while(j<n)
	{
		if(lmx[i]<rmn[j]) i++;
		else
		{
			rs=max(rs,j-i);
			j++;
		}
	}
	return rs;
}

void DoTest()
{
	int arr1[]={5,6,2,3};
	int arr2[]={1,2,3,4,5};
	ASS_EQUAL(findmx(arr1,sizeof(arr1)/sizeof(int)),2);
	ASS_EQUAL(findmx(arr2,sizeof(arr2)/sizeof(int)),0);
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;

	return 0;
}