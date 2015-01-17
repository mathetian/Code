/**
	Question, https://sites.google.com/site/spaceofjameschen/home/array/printthenumbersofform2i5jinincreasingorder--google
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

void print(int n)
{
	vector<int> arr(n,1);
	int i2=0,i3=0,i5=0;
	for(int i=1;i<n;i++)
	{
		int t=min(arr.at(i2)*2,min(arr.at(i3)*3,arr.at(i5)*5));
		arr[i]=t;
		if(arr.at(i2)*2==t) i2++;
		if(arr.at(i3)*3==t) i3++;
		if(arr.at(i5)*5==t) i5++;
	}
	cout<<n<<" "<<arr.at(n-1)<<endl;
}

void DoTest()
{
	for(int i=1;i<10;i++)
		print(i);
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;

	return 0;
}