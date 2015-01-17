#include <iostream>
#include <vector>
using namespace std;

typedef struct _tNode{
	struct _tNode*left;
	struct _tNode*right;
	struct _tNode*parent;
	int flag;int subs;
	_tNode(int id)
	{
		left=right=parent=NULL;
		flag=subs=1;
	}
}Node;

vector<Node*>nodes;

#define RED 1
#define EMPTY 0

int lmr(Node*node)
{
	int a=0;
	if(node->left) a+=lmr(node->left);
	if(node->right) a+=lmr(node->right);
	node->subs+=a;
	return node->subs;
}	

int main()
{
	int N,i,j;cin>>N;nodes=vector<Node*>(N+1,NULL);
	for(i=1;i<=N;i++) nodes[i]=new Node(0);int a,b;
	for(i=0;i<N-1;i++)
	{
		cin>>a>>b;if(!nodes[a]->left) 
		nodes[a]->left=nodes[b];
		else nodes[a]->right=nodes[b];
		nodes[b]->parent=nodes[a];
	}
	lmr(nodes[1]);
	int M;cin>>M;char c;
	while(M--)
	{
		cin>>c>>a;
		if(c=='C')
		{
			int flag=RED;if(nodes[a]->flag==1) 
			flag=EMPTY;nodes[a]->flag=flag;
			if(flag==RED) nodes[a]->subs++;
			else nodes[a]->subs--;
			Node*node=nodes[a]->parent;
			while(node)
			{
				if(flag==RED) node->subs++;
				else node->subs--;
				node=node->parent;
			}
		}
		else cout<<nodes[a]->subs<<endl;
	}
	return 0;
}