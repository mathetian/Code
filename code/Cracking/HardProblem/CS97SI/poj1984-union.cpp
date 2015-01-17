#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

#define INF 0x3fffff

typedef struct _tNode{
	int from,to;
	int dist;char flag;
	_tNode(int id){}
	void set(int a,int b,int c,char d)
	{
		from=a;to=b;dist=c;flag=d;
	}
}EDGE;

typedef struct _ttNode{
	int x,y;int parent;
	_ttNode(int id){x=0x3fffff;y=0x3fffff;parent=id;}
}Node;

vector<Node>nodes;

int find(int id)
{
	if(nodes[id].parent == id) 
		return id;
	else
	{
		int parent = find(nodes[id].parent);
		//'N', 'E', 'S', or 'W'
		switch(flag)
		{
		case 'N':
		break;
		case 'E':break;
		case 'S':break;
		case 'W':break;
		}
	}
}

void union1(int a,int b,int dist,char dir)
{
	nodes[find(b)].parent=find(a);
}

int get(int a,int b)
{
	return abs(nodes[a].x-nodes[b].x)+abs(nodes[a].y-nodes[b].y);
}

int main()
{
	int N,M;int i,j;int a,b,c;char d;
	cin>>N>>M;vector<EDGE> edges(M,0);
	nodes=vector<Node>(N,0);
	for(i=0;i<M;i++)
	{
		cin>>a>>b>>c;cin>>d;
		edges[i].set(a,b,c,d);
	}
	int Q;cin>>Q;int id=0;
	while(Q--)
	{
		cin>>a>>b>>c;
		while(id<c)
		{
			EDGE edge=edges[id];id++;
			int from=edge.from,to=edge.to;
			union1(from,to,edge.dist,edge.flag);
		}
		if(find(a)!=find(b)) cout<<-1<<endl;
		else cout<<get(a,b)<<endl;
	}
	return 0;
}