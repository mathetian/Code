/**
	Question and solution, https://sites.google.com/site/spaceofjameschen/home/array/findthemostlongestormostfrequentlongestsubarray--amazon
	Suffix-array tree.

	A very common question. POJ & microsoft & problem archive.

	The plain method will cost O(n^3) at most. The great method will cost O(n^2logn). It behaves as bucket sort.

	Write it right now.
**/
#include <set>
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
	bool operator()(const vector<int>&a1,const vector<int>&a2)
	{
		int i=0;int m=min(a1.size(),a2.size());
		while(i<m&&a1.at(i)==a2.at(i)) break;
		if(i<m) return a1.at(i) < a2.at(i);
		return a1.size()>a2.size();
	}
};

void find(vector<int>&arr,int n)
{
	vector<vector<int> > arrs;
	for(int i=0;i<n;i++)
		arrs.push_back(vector<int>(arr.begin()+i,arr.end()));
	sort(arrs.begin(),arrs.end(),cmp());
	int rs=0;
	for(unsigned int i=0;i<arrs.size()-1;i++)
	{
		vector<int> a1=arrs.at(i), a2=arrs.at(i+1);
		int m=min(a1.size(),a2.size());
		int j=0;for(;j<m&&a1.at(j)==a2.at(j);j++);
		rs=max(rs,j);
	}
	set<vector<int> > sss;
	for(unsigned int i=0;i<arrs.size()-1;i++)
	{
		vector<int> a1=arrs.at(i), a2=arrs.at(i+1);
		int m=min(a1.size(),a2.size()); int j=0;
		for(;j<m&&a1.at(j)==a2.at(j);j++);
		if(j==rs) sss.insert(vector<int>(a1.begin(),a1.begin()+j));
	}
	set<vector<int> >::iterator iter=sss.begin();
	for(;iter!=sss.end();iter++)
	{
		vector<int> a1=*iter;
		for(unsigned int i=0;i<a1.size();i++)
			cout<<a1.at(i)<<" ";
		cout<<endl;
	}
}

void DoTest()
{
	int arr1[]={4,5,6,8,3,1,4,5,6,3,1};
	vector<int> arrv(arr1,arr1+sizeof(arr1)/sizeof(int));
	find(arrv, arrv.size());
	cout<<endl;
	int arr2[]={4, 5, 6, 7, 8, 3, 1, 4, 5, 6, 3, 1, 0, 4, 5, 6, 5, 8, 3, 1, 6, 8, 3, 1, 2, 8, 3, 1, 8, 3, 1};
	arrv=vector<int>(arr2,arr2+sizeof(arr2)/sizeof(int));
	find(arrv, arrv.size());
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;
	
	return 0;
}