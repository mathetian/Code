/**
	Question, https://sites.google.com/site/spaceofjameschen/home/dynamic-programming/find-longest-increasing-subsequence

	There is a O(n^2) solution. There is a O(nlogn) algorithm for it in http://stackoverflow.com/questions/2631726/how-to-determine-the-longest-increasing-subsequence-using-dynamic-programming
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

void findlongest(int*arr,int n)
{
	vector<int> prev(n,-1);
	vector<int> length(n,1);
	int mx=1;int k=0;
	for(int i=1;i<n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(arr[i]>=arr[j])
			{
				if(length.at(i)<length.at(j)+1)
				{
					prev[i]=j;length[i]=length.at(j)+1;
					mx=max(prev[i],mx);k=i;
				}
			}
		}	
	}
	string rs;
	while(k!=-1)
	{
		rs=itoa(arr[k])+" "+rs;
		k=prev[k]; 
	}
	cout<<rs<<endl;
}

void DoTest()
{
	int arr[]={6, 20, 5, 31, 19, 49, 39, 58, 79};
	findlongest(arr, sizeof(arr)/sizeof(int));
}

int main()
{
	DoTest();

	cout<<"Passed All Test"<<endl;
	return 0;
}