/**
	No problem with this problem. However, please give a proof ?

	http://stackoverflow.com/questions/8334981/find-pair-of-numbers-in-array-that-add-to-given-sum

	If we are given a unsorted array. Try to use radix-sort and use the general solution.

	Example, 0,1,5,6,7,9,11,12,20,21,22,24,27,28,32,33,34
	Target 40, 
	28 + 12 = 40
	33 + 7 = 40
	34 + 6 = 40
	There are 3 pairs

	Got the perfect solution ! Wrong idea !
**/

/**
	If there is a solution (i*, j*), suppose that i reaches i* before j reaches j*. 
	Since for all j' between j* and j we know that a[j'] > a[j*], we can extrapolate that a[i] + a[j'] > a[i*] + a[j*] = target.
	Therefore, that all the following steps of the algorithm will cause j to decrease until it reaches j* (or an equal value) 
	without giving i a chance to advance forward and "miss" the solution.
	
	The interpretation in the other direction is similar.
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

void suntozero(vector<int>&arr, int target)
{
	int n=arr.size();
	int i=0,j=n-1;
	while(i<j)
	{
		int m=arr.at(i)+arr.at(j);
		if(m==target)
		{
			cout<<i<<"("<<arr.at(i)<<"), "<<j<<"("<<arr.at(j)<<")"<<endl;
			i++;j--;
		}
		else if(m>target) j--;
		else i++;
	}
}

void DoTest()
{
	int arr[]={0,1,5,6,7,9,11,12,20,21,22,24,27,28,32,33,34};
	vector<int> arrv(arr,arr+sizeof(arr)/sizeof(int));
	suntozero(arrv, 40);
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;

	return 0;
}