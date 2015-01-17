#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

struct _tNode
{
	struct _tNode*left;
	struct _tNode*right;
	char flag;
	_tNode(char f)
	{
		left=NULL;right=NULL;
		flag=f;
	}
};

typedef struct _tNode Node;

int main()
{
	int T,i,n;string str;
	cin>>T;while(T--)
	{
		cin>>str; n=str.size();
		
		vector<Node*> nodes(n,NULL);
		for(i=0;i<n;i++)
			nodes[i]=new Node(str.at(i));
		
		stack<Node*> sNodes;
		for(i=0;i<n;i++)
		{
			if(str.at(i)>='A'&&str.at(i)<='Z')
			{
				nodes.at(i)->right=sNodes.top();
				sNodes.pop();
				nodes.at(i)->left=sNodes.top();
				sNodes.pop();
			}
			sNodes.push(nodes.at(i));
		}
		Node*root=sNodes.top();sNodes.pop();
		queue<Node*> qNodes;qNodes.push(root);
		string str1;while(!qNodes.empty())
		{
			Node*node=qNodes.front();
			qNodes.pop();
			str1.push_back(node->flag);
			if(node -> flag >='A' && node -> flag <='Z')
			{
				qNodes.push(node->left);
				qNodes.push(node->right);
			}
		}

		reverse(str1.begin(),str1.end());
		cout<<str1<<endl;
		// for(i=0;i<n;i++)
		// { delete nodes[i];nodes[i]=NULL; }
	
	}
	return 0;
}