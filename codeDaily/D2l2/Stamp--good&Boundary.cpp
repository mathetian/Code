#include <vector>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

/*int getMinimumCost(string const &desiredColor,int stampCost,int pushCost) 
{
	int i=0;int n=desiredColor.size();
	vector<vector<vector<int> > >dp(n,vector<vector<int> >(n+1,vector<int>(4,-1)));
	if(desiredColor.at(0)=='R') dp[0][1][0]=stampCost+pushCost;
	else if(desiredColor.at(0)=='G') dp[0][1][1]=stampCost+pushCost;
	else if(desiredColor.at(0)=='B') dp[0][1][2]=stampCost+pushCost;
	else 
	{
		dp[0][1][0]=stampCost+pushCost;
		dp[0][1][1]=stampCost+pushCost;
		dp[0][1][2]=stampCost+pushCost;
	}
	dp[0][1][3]=stampCost+pushCost;

	for(int i=1;i<n;i++)
	{
		for(int L=1;L<=i;L++)
		{
			int j=i-L+1;int k;
			if(desiredColor.at(i)=='R')
			{
				if(dp[j-1][L][3]==-1) dp[i][L][0]=-1;
				else
				{
					for(k=j;k<=i;k++)
					{
						if(desiredColor.at(k)=='*') continue;
						if(desiredColor.at(k)=='R') continue;
						break;
					}
					if(k==i+1) dp[i][L][0]=dp[j-1][L][3]+pushCost;
					dp[i][L][3]=dp[i][L][0];
				}
			}
			else if(desiredColor.at(i)=='G')
			{
				if(dp[j-1][L][3]==-1) dp[i][L][1]=-1;
				else
				{
					for(k=j;k<=i;k++)
					{
						if(desiredColor.at(k)=='*') continue;
						if(desiredColor.at(k)=='G') continue;
						break;
					}
					if(k==i+1) dp[i][L][1]=dp[j-1][L][3]+pushCost;
					dp[i][L][3]=dp[i][L][1];
				}
			}
			else if(desiredColor.at(i)=='B')
			{
				if(dp[j-1][L][3]==-1) dp[i][L][2]=-1;
				else
				{
					for(k=j;k<=i;k++)
					{
						if(desiredColor.at(k)=='*') continue;
						if(desiredColor.at(k)=='B') continue;
						break;
					}
					if(k==i+1) dp[i][L][2]=dp[j-1][L][3]+pushCost;
					dp[i][L][3]=dp[i][L][2];
				}
			}
			else
			{
				if(dp[j-1][L][3]==-1) {dp[i][L][0]=-1;continue;}
							
				for(k=j;k<=i;k++)
				{
					if(desiredColor.at(k)!='*') break;
				}
				if(k<=i)
				{
					char color=desiredColor.at(k);
					for(k=j;k<=i;k++)
					{
						if(desiredColor.at(k)=='*') continue;
						if(color!=desiredColor.at(k)) break;
					}
					if(k<=i){}
					else
					{
						if(color=='R') dp[i][L][0]=dp[j-1][L][3]+pushCost;
						if(color=='G') dp[i][L][1]=dp[j-1][L][3]+pushCost;
						if(color=='B') dp[i][L][2]=dp[j-1][L][3]+pushCost;
						dp[i][L][3]=dp[j-1][L][3]+pushCost;
					}
				}
				else
				{
					dp[i][L][0]=dp[j-1][L][3]+pushCost;
					dp[i][L][1]=dp[j-1][L][3]+pushCost;
					dp[i][L][2]=dp[j-1][L][3]+pushCost;
					dp[i][L][3]=dp[j-1][L][3]+pushCost;
				}
			}
		}
		int k=0;
		for(k=0;k<=i;k++)
		{
			if(desiredColor.at(k)!='*') break;
		}
		if(k>i) 
		{
			dp[i][i+1][0]=stampCost*(i+1)+pushCost;
			dp[i][i+1][1]=dp[i][i+1][0];
			dp[i][i+1][2]=dp[i][i+1][0];
			dp[i][i+1][3]=dp[i][i+1][0];
		}
		else
		{
			char color=desiredColor.at(k);
			for(k=0;k<=i;k++)
			{
				if(desiredColor.at(k)=='*') continue;
				if(color!=desiredColor.at(k)) break;
			}
			if(k<=i){}
			else
			{
				if(color=='R') dp[i][i+1][0]=stampCost*(i+1)+pushCost;
				if(color=='G') dp[i][i+1][1]=stampCost*(i+1)+pushCost;
				if(color=='B') dp[i][i+1][2]=stampCost*(i+1)+pushCost;
				dp[i][i+1][3]=stampCost*(i+1)+pushCost;
			}
		}
	}
	int mx=0x3fffff;
	for(int L=1;L<=n;L++)
	{
		for(int k=0;k<3;k++)
		{
			if(dp[n-1][L][k]!=-1)
			{
				mx=min(mx,dp[n-1][L][k]);
			}
		}
	}
	return mx;
}*/



int getMinimumCost(string const &desiredColor,int stampCost,int pushCost) 
{
	int n=desiredColor.size();int i,j,k;int L;
	int mincost=0x3ffffff;
	for(L=1;L<=n;L++)
	{	
		int dp[51][3];const char*colors="RGB";
		for(i=0;i<51;i++) for(j=0;j<3;j++) dp[i][j]=0x3ffffff;
		dp[0][0]=0;dp[0][1]=0;dp[0][2]=0;
		for(i=L-1;i<n;i++)
		{
			for(j=0;j<3;j++)
			{
				char color=colors[j];
				char first='*';
				// i-L+1 ... i
				for(k=i-L+1;k<=i;k++)
				{
					if(desiredColor.at(k)=='*') continue;
					if(first=='*') first=desiredColor.at(k);
					if(first!=desiredColor.at(k)) break;
				}
				if(k<=i) break;
				if(first!='*'&&first!=color) continue;
				int mv=0x3ffffff;
				for(k=i-L+1;k<=i;k++)
				{
					for(int p=0;p<3;p++)
					{
						if(k==i-L+1||p==j) mv=min(mv,dp[k][p]);
					}
				}
			//	if(L==1) cout<<i<<" "<<j<<" "<<mv<<endl;
				dp[i+1][j]=mv+1;
			}
		}
		int a=min(dp[n][0],min(dp[n][1],dp[n][2]));
		if(a >= 0x3ffffff) continue;
		mincost=min(stampCost*L+a*pushCost,mincost);
	}
	return mincost;
}

/*int main()
{
	string desiredColor="R*BGGRRBB";
	cout<<getMinimumCost(desiredColor,1,100000)<<endl;
	return 0;
}*/