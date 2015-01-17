/**http://www.cnblogs.com/zhangchaoyang/articles/2012070.html**/
#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include <assert.h>

#define ASSERT_EQUAL(a,b) assert(a==b)

//最大子序列、最长递增子序列、最长公共子串、最长公共子序列、字符串编辑距离

//size != 0
int maxsubarray(int*arr,int n)
{
	int max_sofar=arr[0], max_endhere=arr[0];
	for(int i=1;i<n;i++)
	{
		max_endhere=max(max_endhere+arr[i],arr[i]);
		max_sofar=max(max_sofar,max_endhere);
	}
	return max_sofar;
}

int maxlenincrarr(int*arr,int n)
{
	vector<int> mxlen(n,1);
	int mx_len=1;
	for(int i=1;i<n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(arr[i]>arr[j])
				mxlen[i]=max(mxlen[i], mxlen[j]+1);
		}
		mx_len=max(mx_len, mxlen[i]);
	}
	return mx_len;
}

string LCSubstr(const string&s1, const string&s2)
{
	int l1=s1.size(),l2=s2.size(); int z=0; string rs;
	vector<vector<int> >dp(l1,vector<int>(l2,0));
	for(int i=0;i<l1;i++)
	{
		for(int j=0;j<l2;j++)
		{
			if(s1.at(i)==s2.at(j))
			{
				if(i==0||j==0)
					dp[i][j]=1;
				else 
					dp[i][j]=dp[i-1][j-1]+1;
				if(dp[i][j]>z)
				{
					z=dp[i][j];
					rs=s1.substr(i-z+1,z);
				}
			}
			else dp[i][j]=0;
		}
	}
	return rs;
}

int LCSeqence(const string&s1, const string&s2)
{
	int l1=s1.size(),l2=s2.size();
	vector<vector<int> >dp(l1,vector<int>(l2,0));
	for(int i=0;i<l1;i++)
	{
		for(int j=0;j<l2;j++)
		{
			if(s1.at(i)==s2.at(j)&&(i==0||j==0))
				dp[i][j]=1;
			else if(s1.at(i)==s2.at(j))
				dp[i][j]=1+dp[i-1][j-1];
			else if(i!=0 && j!=0)
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[l1-1][l2-1];
}

int EditDistance(const string&s1, const string&s2)
{
	int l1=s1.size(),l2=s2.size();
	vector<vector<int> >dp(l1+1,vector<int>(l2+1,0));
	for(int i=0;i<=l1;i++)
		dp[i][0]=i;
	for(int i=0;i<=l2;i++)
		dp[0][i]=i;

	for(int i=0;i<l1;i++)
	{
		for(int j=0;j<l2;j++)
		{
			if(s1.at(i)==s2.at(j))
				dp[i+1][j+1]=dp[i][j];
			else
				dp[i+1][j+1]=min(dp[i][j],min(dp[i][j+1],dp[i+1][j]))+1;
		}
	}
	return dp[l1][l2];
}

void DoTest()
{
	int arr1[]={34, -49, 27, 9, 23}; int arr2[]={1,2,-3,2};

	ASSERT_EQUAL(maxsubarray(arr1,sizeof(arr1)/sizeof(int)), 59);
	ASSERT_EQUAL(maxsubarray(arr2,sizeof(arr2)/sizeof(int)), 3);

	ASSERT_EQUAL(maxlenincrarr(arr1,sizeof(arr1)/sizeof(int)), 3);
	ASSERT_EQUAL(maxlenincrarr(arr2,sizeof(arr2)/sizeof(int)), 2);

	string s1="abcab", s2="dca1", s3="nothing";
	ASSERT_EQUAL(LCSubstr(s1,s2), "ca");
	ASSERT_EQUAL(LCSubstr(s1,s3), "");

	ASSERT_EQUAL(LCSeqence(s1,s2), 2);
	
	ASSERT_EQUAL(EditDistance(s1,s2), 3);
	ASSERT_EQUAL(EditDistance(s1,s3), 7);
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;

	return 0;
}