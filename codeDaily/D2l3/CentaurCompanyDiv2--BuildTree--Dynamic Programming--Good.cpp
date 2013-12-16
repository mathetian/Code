#include <vector>
#include <string>
#include <map>
using namespace std;

typedef struct _tNode{
	int value;int64 mx;
	struct _tNode*fChild;
	struct _tNode*parent;
	struct _tNode*next;
	_tNode(int val){fChild=NULL;parent=NULL;next=NULL;value=val;mx=1;}
}Node;

vector<int> a;vector<int> b;int n;

void buildTree(Node*parent,Node*cur)
{
	//cout<<" cur:"<<cur->value;
	int n=a.size();
	for(int i=0;i<n;i++)
	{
		int flag=0;
		if(cur->value==a.at(i))
		{
			if(parent&&parent->value==b.at(i)) continue;
			flag=1;
		}
		if(cur->value==b.at(i))
		{
			if(parent&&parent->value==a.at(i)) continue;
			flag=2;
		}
		if(flag!=0)
		{
			Node*now=new Node(b.at(i));now->parent=cur;
			if(flag==2) now->value=a.at(i);
			if(!cur->fChild) cur->fChild=now;
			else
			{
				Node*end=cur->fChild;
				now->next=end->next;
				end->next=now;
			}
		}
	}
	Node*child=cur->fChild;
	while(child)
	{
		buildTree(cur,child);
		child=child->next;
	}
}

Node*buildTree()
{
	Node *root=new Node(a.at(0));
	buildTree(NULL,root);
	return root;
}

/*int64 dfs(map<int,int>&iim,int index,int most,vector<int>&distinct)
{
	if(index==most) return 0;
	else
	{
		int a=distinct.at(index),b=iim[a];
		int64 c=1;for(int i=0;i<=b;i++)
		{

		}
	}
}*/
void lrm(Node*root)
{
	Node*child=root->fChild;if(!child) return;
	while(child)
	{
		lrm(child);child=child->next;
	}
	child=root->fChild;
	int64 num=1;
	while(child)
	{
		num*=(child->mx+1);child=child->next;
	}
	root->mx=num;
}

int64 cal(Node*root)
{
	int64 num=0;Node*child=root->fChild;
	while(child)
	{
		num+=cal(child);
		child=child->next;
	}
	root->mx+=num;
	return root->mx;
}

int64 count(vector<int> const &a1, vector<int> const &b1) 
{
	a=vector<int>(a1.begin(),a1.end());b=vector<int>(b1.begin(),b1.end());
	n=a.size();Node*root=buildTree();lrm(root);return cal(root)+1;
}
