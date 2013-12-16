#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <algorithm>
using namespace std;

//summary the problem, get n step from origin place to destination
//graph is hard to get
//hard to estimate time and memory
#define FFI(i,a,b) for(i=a;i<b;i++)
#define MOD 1000000007

typedef long long _int64;

vector<int> x,y;int n,m;_int64 dp[105][105][51];

int dfs(int a,int b,int m)
{
//	cout<<a<<" "<<b<<" "<<m<<endl;
	_int64&res=dp[a+50][b+50][m];
	if(res==-1)
	{
		if(abs(a)+abs(b)>m) res=0;
		else if(m==0)
		{
			if(a==0&&b==0) res=1; else res=0;
		} 
		else
		{
			res=(dfs(a-1,b,m-1)+dfs(a+1,b,m-1))%MOD;
			res=(res+dfs(a,b-1,m-1))%MOD;res=(res+dfs(a,b+1,m-1))%MOD;
		}
	}
	return res;
}

int calc(vector<int> const &x1,vector<int> const &y1,int m1) 
{	
	x=vector<int>(x1.begin(),x1.end());y=vector<int>(y1.begin(),y1.end());
	int i,j,k;n=x.size();m=m1;_int64 rs=0;memset(dp,-1,sizeof(dp));
	FFI(i,-51,102)
	{
		FFI(j,-51,102)
		{
			FFI(k,0,n) if(abs(i-x.at(k))+abs(j-y.at(k))>m) break;
			if(k<n) continue;_int64 r1=1;
			FFI(k,0,n)
			{
				int a=abs(i-x.at(k));int b=abs(j-y.at(k));r1=(r1*dfs(a,b,m))%MOD;
			}
			rs=(rs+r1)%MOD;
		}
	}
    return rs;
}

/*int main()
{
	int a1[]={20, 30};int a2[]={20, 30}; 
	vector<int> x1(a1,a1+2);vector<int>y1(a2,a2+2);
	cout<<calc(x1,y1,50)<<endl;
	return 0;
}
*/