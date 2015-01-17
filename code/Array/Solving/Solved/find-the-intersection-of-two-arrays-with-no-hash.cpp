/**
	Question, https://sites.google.com/site/spaceofjameschen/home/tree/find-the-intersection-of-two-arrays-with-no-hash
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

vector<int> intersect(int*arr1,int*arr2,int n1,int n2)
{
	int mx1=arr1[0],mn1=arr2[0]; int mx2=arr2[0],mn2=arr2[0];
	for(int i=1;i<n1;i++) {mx1=max(mx1,arr1[i]);mn1=min(mn1,arr1[i]);}
	for(int i=1;i<n2;i++) {mx2=max(mx2,arr2[i]);mn2=min(mn2,arr2[i]);}
	int mx=min(mx1,mx2),mn=max(mn1,mn2);
	vector<int> rs; if(mx<mn) return rs;
	vector<int> table(mx-mn+1,0);set<int>rs1;
	for(int i=0;i<n1;i++) if(arr1[i]>=mn&&arr1[i]<=mx) table[arr1[i]-mn]=1;
	for(int i=0;i<n2;i++) if(arr2[i]>=mn&&arr2[i]<=mx&&table[arr2[i]-mn]==1) rs1.insert(arr2[i]);

	copy(rs1.begin(),rs1.end(),back_inserter(rs));

	return rs;
}

void DoTest()
{
	int arr11[]={34, 8, 10, 3, 2, 80, 30, 33, 1};
	int arr12[]={1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int>arr=intersect(arr11, arr12, sizeof(arr11)/sizeof(int), sizeof(arr12)/sizeof(int));
	for(unsigned int i=0;i<arr.size();i++) cout<<arr[i]<<" "; cout<<endl;
	int arr21[]={10};
	arr=intersect(arr21, arr12, sizeof(arr21)/sizeof(int), sizeof(arr12)/sizeof(int));
	for(unsigned int i=0;i<arr.size();i++) cout<<arr[i]<<" "; cout<<endl;
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;
	return 0;
}