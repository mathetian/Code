#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
	way 1, change it to lcs
**/

int dp[100][100];
/**
	dp[a][b] = dp[a-1][b-1] + 1 or max(dp[a][b-1],dp[a-1][b]) (a >=1, b >= 1)
	dp[0][0], dp[a][0], dp[0][b]
	dp[a][0] = 
**/
#define FF(i,n) for(i = 0;i < n;i++)
#define FS(i,a,b) for(i = a;i < b;i++)

void print(vector <int > a1)
{
	int i;
	for(i = 0;i < a1.size();i++)
		cout<<a1.at(i)<<" ";
	cout<<endl;
}

int LCS(vector <int> & a1, vector<int> &a2)
{
	int len1 = a1.size(), len2 = a2.size();
	
	if(a1.at(0) == a2.at(0)) dp[0][0] = 1;
	else dp[0][0] = 0;
	
	int i, j; 
	
	FS(i,1,len1) if(a1.at(i) == a2.at(0)) dp[i][0] = 1;
	else dp[i][0] = dp[i - 1][0];
	FS(i,1,len2) if(a1.at(0) == a2.at(i)) dp[0][i] = 1;
	else dp[0][i] = dp[0][i-1];

	FS(i,1,len1)
	{
		FS(j,1,len2)
		{
			if(a1.at(i) == a2.at(j))
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[len1-1][len2-1];
}

int LIS1(vector <int> arr)
{
	int rs = 1; int len = arr.size();
	int low = 0, high = len - 1;
	
	vector <int> arr2 = arr;
	sort(arr2.begin(), arr2.end());

	return LCS(arr,arr2);
}

int LIS2(vector <int> arr)
{
	int i, j; int len = arr.size();
	vector<int> f(len,1);
	FF(i,len)
	{
		for(j = i-1;j >= 0;j--)
		{
			if(arr.at(j) < arr.at(i))
				f[i] = max(f[i],f[j] + 1);
		}
	}
	int rs = 1;
	FF(i,len) rs = max(rs,f[i]);
	return rs;
}

int LIS3(vector <int> arr)
{
	int rs = 1, len = arr.size(), i, j;
	vector <int> f(len, 0);
	f[0] = arr.at(0);
	for(i = 1;i < len;i++)
	{	
		for(j = rs - 1;j >= 0; j--)
			if(arr.at(i) > f.at(j)) break;
		if(j == -1)
			f[0] = min(f[0],arr.at(i));
		else 
		{
			f[j + 1] = arr.at(i);
			rs = max(rs, j + 2);
		}
	}
	return rs;
}

int main()
{
	int arr3[]={-1,1,5,4,0,2,3};
	vector <int> arr(arr3, arr3 + sizeof(arr3)/sizeof(int));
	cout<<LIS1(arr)<<endl;
	cout<<LIS2(arr)<<endl;
	cout<<LIS3(arr)<<endl;
}