#include <iostream>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

int maps[250][250];
int N,M;

int path[250]; int pathnum;
int used[250]; int rs;

bool dfs(int index)
{
	if(index == M-1)
	{
		int m = 0x3fffff;
		for(int j = 0;j < pathnum-1;j++)
			m=min(m,maps[path[j]][path[j+1]]);
		for(int j = 0;j < pathnum-1;j++)
		{
			maps[path[j]][path[j+1]]-=m;
			maps[path[j+1]][path[j]]+=m;
		}
		rs+=m;
		return true;
	}

	bool flag = false;
	for(int i=0;i<M;i++)
	{
		if(used[i] == 0 && maps[index][i] > 0)
		{
			path[pathnum++] = i;
			used[i] = 1;
			if(dfs(i) == 1) flag = true;
			used[i] = 0;
			pathnum--;
		}
	}
	return flag;
}

int maxflow()
{
	rs=0; bool flag = true;
	while(flag)
	{
		flag = false;
		for(int i=1;i<M;i++)
		{
			if(maps[0][i] > 0)
			{
				memset(used,0,sizeof(used));pathnum=0;
				used[pathnum]=1;path[pathnum++] = 0;
				path[pathnum++] = i;
				flag = dfs(i);
			}
		}
	}
	return rs;
}

int main()
{	
	while(cin>>N>>M)
	{
		int i,j;
		FF(i,M)FF(j,M)
		{
			if(i==j) maps[i][j]=0;
			else maps[i][j]=-1;
		}
		int a,b,c;
		FF(i,N)
		{
			cin>>a>>b>>c;
			maps[a-1][b-1]=c;
			maps[b-1][a-1]=0;
		}
		cout<<maxflow()<<endl;
	}
	return 0;
}