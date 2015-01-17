/**
	https://sites.google.com/site/spaceofjameschen/home/array/compute-the-sum-of-elements-in-after-nth-iteration-for-below-operation-on-array
	A better explanation,
	http://stackoverflow.com/questions/16885465/sum-of-all-elements-of-an-array-after-n-iterations

	Conclude, calculate C(n,k) = C(n-1,k) + c(n-1,k-1). Can get all coefficients C(n,k) in linear time, and linear space complexity 
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

int cc[100][100];

void precompute()
{
	for(int i=1;i<100;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0||j==i) cc[i][j]=1;
			cc[i][j]=cc[i-1][j-1]+cc[i-1][j];
		}
	}
}

int iteratork(vector<int> &arr,int k)
{
	if(arr.size() <= k) return -1;
	if(k==0)
	{
		int rs=0;
		for(int i=0;i<arr.size();i++) rs+=arr[i];
		return rs;
	}
	int rs=0; int flag=1;

	for(int i=0;i<=k;i++,flag=-flag)
		rs+=cc[k][i]*arr.at(i);

	int rs2=0;
	int n=arr.size();
	for(int i=0;i<=k;i++,flag=-flag)
		rs2+=cc[k][i]*arr.at(n-k+i-1);
	
	cout<<rs<<" "<<rs2<<endl;
	return rs2-rs;
}

void DoTest()
{
	int arr[]={4, 6, 8, 3, 6};
	vector<int> arr1(arr,arr+sizeof(arr)/sizeof(int));

	ASS_EQUAL(iteratork(arr1,0),27);
	ASS_EQUAL(iteratork(arr1,1),-2);
	ASS_EQUAL(iteratork(arr1,2),1);
	ASS_EQUAL(iteratork(arr1,3),8);
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;
	return 0;
}