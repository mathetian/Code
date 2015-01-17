#include <iostream>
using namespace std;

#include <string.h>

int N,M;
int maps[505][505];
bool used[5];

int path[505], used[505]; 
int pathnum, rs;

bool dfs(int index)
{
	if(index == N+M-1)
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
		for(int i=1;i<N+1;i++)
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
		memset(maps,0,sizeof(maps));
		for(int i=0;i<N;i++)
			maps[0][i+1] = 1;
		for(int i=0;i<M;i++)
			maps[N+i+1][N+M+1] = 1;
		for(int i=0;i<N;i++)
		{
			int a,b;cin>>a;
			while(a--)
			{
				cin>>b;
				maps[i+1][N+b] = 1;
			}
		}
		cout<<maxflow()<<endl;
	}
	return 0;
}
