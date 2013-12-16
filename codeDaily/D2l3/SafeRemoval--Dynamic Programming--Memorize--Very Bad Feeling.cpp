#include <vector>
#include <string>
#include <string.h>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

int n,k;vector<int>arr[4];
int dp[51][51][51][51];
int flag=0;
int dfs(int a,int b,int c,int d)
{
	int&res=dp[a][b][c][d];if(res!=-1) return res;
	res=arr[0][a]+arr[1][b]+arr[2][c]+arr[3][d];
//	cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<res<<" "<<arr[3][d]<<endl;
	if(res%4==0){res=0; return res;}
	if(a+b+c+d==n-k){flag=1;return res;}res=0;
	if(a>=1) res=max(res,dfs(a-1,b,c,d));
	if(b>=1) res=max(res,dfs(a,b-1,c,d));
	if(c>=1) res=max(res,dfs(a,b,c-1,d));
	if(d>=1) res=max(res,dfs(a,b,c,d-1));
	return res;
}

int removeThem(vector<int> const &seq, int k1) 
{
	vector<int>ss(seq.begin(),seq.end());sort(ss.rbegin(),ss.rend());
	int i;int m;FF(i,4) arr[i].push_back(0);n=seq.size();k=k1;
	FF(i,ss.size())
	{ 
		vector<int>&arr1=arr[ss.at(i)%4];arr1.push_back(ss.at(i)+arr1.at(arr1.size()-1));
	}
	memset(dp,-1,sizeof(dp));dfs(arr[0].size()-1,arr[1].size()-1,arr[2].size()-1,arr[3].size()-1);
    if(flag==0) return -1;return dp[arr[0].size()-1][arr[1].size()-1][arr[2].size()-1][arr[3].size()-1];
}
