#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <string.h>

#define SZ 2005
#define FF(i,n) for(i = 0;i < n;i++)

typedef struct{
	vector <int> connected;
	vector <int> sons;
}Node;

Node   nodes[SZ + 1];
int  visited[SZ + 1];

void dfs(int a)
{
	Node & n = nodes[a];visited[a] = 1;
	int connum = n.connected.size();
	int i; FF(i,connum)
	{   
		if(visited[n.connected.at(i)] == 0)
		{
			n.sons.push_back(n.connected.at(i));
			dfs(n.connected.at(i));
		}
	}
}

int num; int xxxx; int id;

int dfs2(int a)
{
	Node & n = nodes[a];

	int sonNum = n.sons.size();

	int sonsTotal = 0, mxson = 0; 
	
	int i;FF(i,sonNum)
	{
		int a1 = dfs2(n.sons.at(i));
		sonsTotal += a1;
		mxson = max(mxson,a1);
	}

	if(sonNum != 0)
	{
		if(num - sonsTotal - 1 != 0)
			mxson = max(mxson, num - sonsTotal - 1); 
	}
	else if(num - sonsTotal - 1 != 0)
		mxson = num - sonsTotal - 1;

	if(xxxx > mxson)
	{
		id = a;xxxx = mxson;
	}
	else if(xxxx == mxson && a < id)
	{
		id = a;xxxx = mxson;
	}

	return sonsTotal + 1;
}

int main()
{
	int t, i, a, b; cin>>t;
	while(t--)
	{
		memset(nodes,0,sizeof(Node)*(SZ+1));
		memset(visited,0,sizeof(visited));

		cin>>num; 
		if(num == 1)
		{
			cout<<1<<" "<<0<<endl;
			continue;
		}

		FF(i,num-1)
		{
			cin>>a>>b;
			
			Node & n1 = nodes[a];
			Node & n2 = nodes[b];
			n1.connected.push_back(b);
			n2.connected.push_back(a);
		}
		dfs(1);xxxx = 0x3ffff; id = 0; dfs2(1);
		cout<<id<<" "<<xxxx<<endl;
	}
}