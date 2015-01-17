/**
	Similar question, 有25匹马，每次只能五匹一起跑，那么最少跑几次，才能确定前三甲呢？ The answer is seven.

	Question, https://sites.google.com/site/spaceofjameschen/home/array/find-top-5-largest-numbers-from-3-sorted-arrays

	Boundary, notice the duplicate value.

	The least comparation
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

void findtop5(vector<vector<int> >&arr)
{
	assert(arr.size()==3); int a[3];
	for(int i=0;i<3;i++) a[i]=arr[i].size()-1;
	int num=0;while(a[0]>=0||a[1]>=0||a[2]>=0)
	{
		int aa[3]; aa[0]=-0x3ffff;aa[1]=-0x3ffff;aa[2]=-0x3ffff;
		if(a[0]>=0) aa[0]=arr[0][a[0]];
		if(a[1]>=0) aa[1]=arr[1][a[1]];
		if(a[2]>=0) aa[2]=arr[2][a[2]];
		int t=max3(aa[0],aa[1],aa[2]);
		cout<<t<<endl;num++;if(num==5) break;
		if(a[0]>=0&&arr[0][a[0]]==t) a[0]--;
		else if(a[1]>=0&&arr[1][a[1]]==t) a[1]--;
		else a[2]--;
	}	
}

void DoTest()
{
	int a1[]={2,4,9,16,19,68,78}; 
	int a2[]={4,8,67,106,109,115,120}; 
	int a3[]={9,15,19,108,119,130,190};
	vector<vector<int> > arr;
	arr.push_back(vector<int>(a1,a1+sizeof(a1)/sizeof(int)));
	arr.push_back(vector<int>(a2,a2+sizeof(a2)/sizeof(int)));
	arr.push_back(vector<int>(a3,a3+sizeof(a3)/sizeof(int))); 

	findtop5(arr);
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;

	return 0;
}