/**
	Question, https://sites.google.com/site/spaceofjameschen/home/dynamic-programming/find-minimum-coin-changes----amazon

	Not a very google example for dynamic programming
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

int findminchange(vector<int>&arr,int target)
{
	vector<int>f(target+1,0x3fffff); 
	sort(arr.begin(),arr.end());
	f[0]=0;
	for(int i=0;i<=target;i++)
	{
		for(unsigned int j=0;j<arr.size()&&arr.at(j)<=i;j++)
			f[i]=min(f[i],f[i-arr.at(j)]+1);
	}
	
	return f[target]==0x3fffff?-1:f[target];
}

void DoTest()
{
	int arr[]={5,2};
	vector<int> arrv(arr,arr+sizeof(arr)/sizeof(int));
	ASS_EQUAL(findminchange(arrv, 0),0);
	ASS_EQUAL(findminchange(arrv, 2),1);
	ASS_EQUAL(findminchange(arrv, 3),-1);
	ASS_EQUAL(findminchange(arrv, 5),1);
	ASS_EQUAL(findminchange(arrv, 7),2);
	ASS_EQUAL(findminchange(arrv, 8),4);
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;

	return 0;
}