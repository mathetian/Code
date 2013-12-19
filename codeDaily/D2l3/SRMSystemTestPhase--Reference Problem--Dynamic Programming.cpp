#include <vector>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

#define MOD 1000000007
#define FF(i,n) for(i=0;i<n;i++)

typedef long long _int64;

_int64 dp[52][4][4];
int data[52];int n;

int ccc[4][4];

int permuate()
{
	int i,j;ccc[0][0]=0;
	for(i=1;i<=3;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(j==0||j==i) ccc[i][j]=1;
			else ccc[i][j]=ccc[i-1][j]+ccc[i-1][j-1];
		}
	}
}
/**
	dp[id][a][b]: id, previous a b
	dp[id][a][b]=sum{get(id+1,c,d)*f(id+1,c,d)}
**/
/** i<a or i==a, j>=b **/
int f(int num, int a,int b)
{
	if(num==a||num==b) return 1;
	return ccc[num][a]*ccc[num-a][b];
}

_int64 get(int id,int a,int b)
{
//	cout<<id<<" "<<a<<" "<<b<<" "<<dp[1][0][0]<<" "<<n<<endl;
	_int64 res=dp[id][a][b];
	if(res!=-1) return res;
	if(id==n) res=1;
	else
	{
	//	if(id==0)
	//	cout<<"test:"<<dp[1][0][0]<<endl;
		res=0;
		//cout<<dp[1][0][0]<<endl;
		int i,j;
		FF(i,4) FF(j,4)
		{
			//cout<<dp[1][0][0]<<endl;
			int num=data[id]; if(i+j>num) break;
			if(i<a) res=(res+f(num,i,j)*get(id+1,i,j))%MOD;
			else if(i==a)
			{
				if(j>=b) res=(res+f(num,i,j)*get(id+1,i,j))%MOD;
			}
			//if(i<=a) cout<<i<<" "<<j<<" "<<res<<" "<<get(id+1,i,j)<<" "<<f(num,i,j)<<endl;
		}
	}
	dp[id][a][b]=res;
	return res;
}

int countWays(vector<string> const &description) 
{
	n=description.size();int i,j,k;memset(data,0,sizeof(data));
	FF(i,n) FF(j,3) data[i]+=(description[i][j]=='Y'?1:0); 
	memset(dp,-1,sizeof(dp));
	permuate();return get(0,4,0);
}

/*int main()
{
	vector<string> description;
	description.push_back("YYY");
	cout<<countWays(description)<<endl;
	return 0;
}*/

