/**
	Question, https://sites.google.com/site/spaceofjameschen/home/array/find-indices-i-j-such-that-sum-of-elements-from-i-to-j-in-both-arrays-is-equal-and-j-i----amazon

	Another question, http://stackoverflow.com/questions/8086240/given-an-array-v-we-need-to-find-two-indices-i-j-such-that-vj-vi-and-j

	Same with stock trade problem.

	Bad feeling.
**/

#include <map>
#include <vector>
#include <iostream>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

void findSameIJ(vector<int> &arr1, vector<int> &arr2)
{
	int m=min(arr1.size(),arr2.size());
	vector<int> d=arr2; map<int,vector<int> >iimap;

	d[0]=arr1.at(0)-arr2.at(0);
	
	int i;
	for(i=1;i<m;i++) d[i]=d[i-1]+arr1.at(i)-arr2.at(i);
	for(i=0;i<m;i++) cout<<d[i]<<" "; cout<<endl;
	iimap[d[0]].push_back(0);
	
	for(i=1;i<m;i++)
	{
		if(iimap.find(d[i]) != iimap.end())
		{
			vector<int> tmp=iimap[d[i]];
			
			for(int j=0;j<tmp.size();j++)
				cout<<tmp.at(j)+1<<" "<<i<<endl;
		}
		iimap[d[i]].push_back(i);
	}
}

int findMxSpace(vector<int> &arr1)
{
	int n=arr1.size(), i, j;

	vector<int> mx(n,0), mn(n,0);
	mx[0]=arr1.at(0);mn[n-1]=arr1.at(n-1);
	for(i=0;i<n;i++)    mx[i]=max(mx[i-1],arr1[i]);
	for(i=n-2;i>=0;i--) mn[i]=min(mn[i+1],arr1[i]);
	
	i=j=0; int rs=0;
	
	int flag=0;
	while(i<n&&j<n)
	{
		while(mx[i]<mn[j]) i++;
		rs=max(j-i,rs); j++;
	}

	return rs;
}

void DoTest1()
{
	int arr1[]={0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0};
	vector<int> va1(arr1,arr1+sizeof(arr1)/sizeof(int));
	int arr2[]={1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0};
	vector<int> va2(arr2,arr2+sizeof(arr2)/sizeof(int));
	findSameIJ(va1,va2);
}

void DoTest2()
{
	int arr[]={88, 55, 42, 23, 98, 78, 54, 5, 17, 14};
	vector<int> arr1(arr,arr+sizeof(arr)/sizeof(int));
	ASS_EQUAL(findMxSpace(arr1), 9);

	int arr2[]={3,4,5,6,7};
	arr1 = vector<int>(arr2,arr2+sizeof(arr2)/sizeof(int));
	ASS_EQUAL(findMxSpace(arr1), 0);

	int arr3[]={3,4,5,1,2,4,5,6};
	arr1 = vector<int>(arr3,arr3+sizeof(arr3)/sizeof(int));
	ASS_EQUAL(findMxSpace(arr1), 4);
}

int main()
{
	DoTest1();
	DoTest2();
	cout<<"Passed All Test"<<endl;
	return 0;
}