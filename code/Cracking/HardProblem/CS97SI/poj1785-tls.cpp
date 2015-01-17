#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

class Node{
public:
	string label;int priority;
	Node*left;Node*right;
	Node(int id){left=NULL;right=NULL;}
};

vector<Node> nodes;

Node*getMx(vector<Node*>&all,int s,int num)
{
	int i,j=s;int n=all.size();for(i=s;i<s+num;i++)
	{ if(all[i]->priority>all[j]->priority) j=i;}
	Node*node=all.at(j);
	if(j!=s) node->left=getMx(all,s,j-s);
	if(j!=s+num-1) node->right=getMx(all,j+1,num-j+s-1);
	return node; 
}

void backTravse(Node*root)
{
	cout<<"(";
	if(root->left) backTravse(root->left);
	cout<<root->label<<"/"<<root->priority;
	if(root->right) backTravse(root->right);
	cout<<")";
}

void sorts(vector<Node*>&all)
{
	int i,j;for(i=0;i<all.size();i++)
	{
		Node*tmp=all.at(i);for(j=i-1;j>=0;j--)
		{
			if((all.at(j)->label)>(tmp->label))
			all[j+1]=all[j]; else break;
		}
		all[j+1]=tmp;
	}
}

int main()
{
	int i,n;while(cin>>n)
	{
		if(n==0) break;string str;
		vector<Node*> nodes(n,NULL);
		for(i=0;i<n;i++)
		{
			cin>>str;int idx=str.find('/');
			nodes[i]=new Node(0);
			nodes[i]->label=str.substr(0,idx);
			nodes[i]->priority=atoi(str.substr(idx+1).c_str());
		}
		sorts(nodes);backTravse(getMx(nodes,0,nodes.size()));cout<<endl;
		for(i=0;i<n;i++){ delete nodes[i];nodes[i]=NULL; }
	}
	return 0;
}