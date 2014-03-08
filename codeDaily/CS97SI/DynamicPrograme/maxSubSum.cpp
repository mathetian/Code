#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
using namespace std;

int maxSubSum(vector<int>&arr)
{
	int n=arr.size(), i;
	assert(n != 0);
	int prev = max(0,arr[0]), mx = prev;
	for(i = 1; i < n;i++)
	{
		mx = max(mx, prev + arr[i]);
		prev = max(0, prev + arr[i]);
	}

	if(mx == 0)
	{
		mx = arr[0];
		for(i = 1;i < n;i++)
			mx = max(mx, arr[i]);
	}
	return mx;
}		

int main()
{
	int arr1[]={-4,-2,-3,-5,-3};
	vector<int> arr(arr1, arr1 + sizeof(arr1)/sizeof(int));
	cout<<maxSubSum(arr)<<endl;
	return 0;
}