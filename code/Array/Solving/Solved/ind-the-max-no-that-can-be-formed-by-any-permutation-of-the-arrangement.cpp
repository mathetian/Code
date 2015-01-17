/**
	Question, https://sites.google.com/site/spaceofjameschen/home/number-and-string/ind-the-max-no-that-can-be-formed-by-any-permutation-of-the-arrangement

	Solution, http://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/
**/
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

struct cmp
{
	bool operator()(const int&a,const int&b)
	{
		stringstream ss1,ss2;
		ss1<<a;ss2<<b;
		string s1=ss1.str(),s2=ss2.str();
		if(s1+s2<s2+s1) return false;
		return true;
	}
};

void print(vector<int>&arr)
{
	int n=arr.size();
	sort(arr.begin(),arr.end(),cmp());
	for(int i=0;i<n;i++)
		cout<<arr[i];
	cout<<endl;
}

void DoTest()
{
	int arr[]={21,9,23,91,3};
	vector<int> arrv(arr, arr+sizeof(arr)/sizeof(int));
	print(arrv);
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;
	return 0;
}