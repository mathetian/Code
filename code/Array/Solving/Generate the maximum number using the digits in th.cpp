/**
	Question, https://sites.google.com/site/spaceofjameschen/home/stl/generate-the-maximum-number-using-the-digits-in-the-array-such-that-it-is-divisible-by-2-3-and-5
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

string itoa(int val)
{
	string str;
	stringstream s1;s1<<val;
	str=s1.str();
	return str;
}
struct cmp
{
	bool operator()(const int&a, const int&b)
	{
		string str1=itoa(a), str2=itoa(b);
		return str1+str2>str2+str1?true:false;
	}
};

int count(int val)
{
	string str=itoa(val); int num=0;
	for(int i=0;i<str.size();i++)
		num+=((str.at(i)-'0')%3);
	return num;
}

int mxval(int*arr,int n)
{
	sort(arr,arr+n,cmp());
	int f2=0;int rs=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==0) f2=1;
		rs=(rs+count(arr[i]))%3;
	}
	if(rs!=0) return -1;
	
	string str;
	for(int i=0;i<n;i++) str+=itoa(arr[i]);
	return atoi(str.c_str());
}

void DoTest()
{
	int arr1[]={1,8,7,6,0};
	int arr2[]={7,7,7,6};

	cout<<mxval(arr1, sizeof(arr1)/sizeof(int))<<endl;
	ASS_EQUAL(mxval(arr1, sizeof(arr1)/sizeof(int)), 8760);
	ASS_EQUAL(mxval(arr2, sizeof(arr2)/sizeof(int)), -1);
}

int main()
{
	DoTest();
	cout<<"Passed All Tests"<<endl;
	return 0;
}