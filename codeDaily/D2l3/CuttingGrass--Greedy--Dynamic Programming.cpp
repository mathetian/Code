#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;

#define FS(i,a,b) for(i=a;i<b;i++)

/**
	dp[i][t]=max(dp[i-1][t],dp[i-1][t-1]+init[i]+grow[i]*t)
	i>=t-1
**/

/*int theMin(vector<int> const &init, vector<int> const &grow, int H) 
{

	int tt=0;int j;FS(j,0,init.size()) tt+=init.at(j);if(tt<=H) return 0; 
	int dp[51][51];memset(dp,0,sizeof(dp));
	int n=init.size(),t,i;FS(t,1,n+1)
	{
		if(t==1)
		{
			dp[0][t]=init[0]+grow[0];FS(i,1,n) 
			dp[i][t]=max(dp[i-1][t],init[i]+grow[i]);
			continue;
		}
		FS(i,t-1,n) 
		{
			dp[i][t]=max(dp[i-1][t],dp[i-1][t-1]+init[i]+grow[i]*t);
			cout<<" "<<dp[i][t]; 
		}
		cout<<endl;
		
	}
	int res[51];FS(t,1,n+1)
	{
		res[t]=0;FS(i,0,n) res[t]+=init[i]+grow[i]*t;
		if(res[t]-dp[n-1][t]<=H) return t;
	}
	return -1;
}*/

/*int theMin(vector<int> const &init, vector<int> const &grow, int H) 
{
	int dp[51][50];int n=init.size(),i,j,t;
	FS(i,0,n) dp[0][i]=init.at(i);
	FS(t,1,n+1) FS(i,0,n) dp[t][i]=dp[t-1][i]+grow.at(i);
	int a=0;FS(i,0,n) a+=dp[0][i];if(a<=H) return 0;
	FS(t,1,n+1)
	{
		set<int>selected;int tmp=0;
		for(i=t;i>=1;i--)
		{
			int mx=-1;FS(j,0,n)
			{
				if(selected.find(j)==selected.end())
				{
					if(mx==-1) mx=j;
					else mx=dp[i][j]>dp[i][mx]?j:mx;
				}
			}
			selected.insert(mx);tmp+=dp[i][mx];
		}
		int res=0;FS(i,0,n) res+=init[i]+grow[i]*t;
	//	cout<<"t:"<<t<<" tmp:"<<tmp<<" "<<res<<endl;
		if(res-tmp<=H) return t;
	}
	return -1;
}*/

void pairsort(vector<int>&init,vector<int>&grow)
{	
	int n=init.size(),i,j;
	for(i=0;i<n;i++)
	{
		int a=init.at(i);int b=grow.at(i);
		for(j=i-1;j>=0;j--)
		{
			if(b<grow.at(j)) 
			{
				init[j+1]=init[j];
				grow[j+1]=grow[j];
			}
			else break;
		}
		init[j+1]=a;grow[j+1]=b;
	}
}

int theMin(vector<int> &init, vector<int> &grow, int H) 
{

	int tt=0;int j;FS(j,0,init.size()) tt+=init.at(j);if(tt<=H) return 0; 
	int dp[51][51];memset(dp,0,sizeof(dp));pairsort(init,grow);
	int n=init.size(),t,i;
	FS(t,1,n+1)
	{
		if(t==1)
		{
			dp[0][t]=init[0]+grow[0];FS(i,1,n) 
			dp[i][t]=max(dp[i-1][t],init[i]+grow[i]);
			continue;
		}
		FS(i,t-1,n) 
		{
			dp[i][t]=max(dp[i-1][t],dp[i-1][t-1]+init[i]+grow[i]*t);
		}
		
	}
	int res[51];FS(t,1,n+1)
	{
		res[t]=0;FS(i,0,n) res[t]+=init[i]+grow[i]*t;
		if(res[t]-dp[n-1][t]<=H) return t;
	}
	return -1;
}
