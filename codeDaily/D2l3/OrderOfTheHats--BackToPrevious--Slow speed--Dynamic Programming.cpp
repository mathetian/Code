#include <vector>
#include <string>
#include <string.h>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)
#define INF 0x3fffff

int dp[1<<21];vector<string>charts;int n;

int dfs(int mask,int m)
{
  int&res=dp[mask];
  if(res!=-1) return res;
  if(m==0) res=0;else
  {
    res=INF;int i,j;FF(i,n)
    {
      if((mask&(1<<i))!=0)
      { 
        int cnt=0;FF(j,n)
        {
          if(charts[i][j]=='Y'&&(mask&(1<<j))!=0) cnt++;
        }
        res=min(res,dfs(mask^(1<<i),m-1)+cnt);
      } 
    }
  }
 // cout<<"mask:"<<mask<<" res:"<<res<<endl;
  return res;
}

int minChanged(vector<string> const &spellChart) 
{
  charts=vector<string>(spellChart.begin(),spellChart.end());
  n=charts.size();memset(dp,-1,sizeof(dp));int cnt=0;
  int i,j;FF(i,n)
  {
    if(charts[i][i]=='Y')
    {
      charts[i][i]='N';cnt++;
    }
  }
  return dfs((1<<n)-1,n)+cnt;
}