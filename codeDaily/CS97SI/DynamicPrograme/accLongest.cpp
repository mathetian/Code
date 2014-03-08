#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

#define SZ 100
#define FF(i,n) for(i = 0;i < n;i++)

int accLongest(vector<int>&arr)
{
	int mx = 1, dp[SZ]; int i,j;
	memset(dp,0,sizeof(dp));
	FF(i,arr.size())
	{
		dp[i] = 1;
		for(j = i -1;j >= 0;j--)
		{
			if(arr.at(i) > arr.at(j))
			{
				dp[i] = max(dp[i], dp[j] + 1);
				mx = max(dp[i], mx);
			}
		}
	}
	return mx;
}

int main()
{
	int arr1[]={3,2,1,-1,5,0,6};
	vector<int>arr(arr1,arr1+sizeof(arr1)/sizeof(int));
	cout<<accLongest(arr)<<endl;
}