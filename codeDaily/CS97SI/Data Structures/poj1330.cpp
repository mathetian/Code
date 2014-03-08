#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
	Node*left,*right,*parent;
	Node(int id);
	/*virtual ~ Node();*/
	int value;
};

Node::Node(int id)
{
	left=NULL;right=NULL;parent=NULL;
	value=id;
}

/*virtual ~ Node::Node()
{
	left=NULL;right=NULL;parent=NULL;
}*/

vector<Node*> vecs;

int main()
{
	int T,N,i,j;int a,b;cin>>T;
	while(T--)
	{
		cin>>N;vecs=vector<Node*>(N+1,NULL);
		vector<int>flags(N,0);
		for(i=1;i<=N;i++) vecs[i]=new Node(i);
		for(i=1;i<=N-1;i++)
		{
			cin>>a>>b;if(vecs[a]->left==NULL) 
			vecs[a]->left=vecs[b];else 
			vecs[a]->right=vecs[b];
			vecs[b]->parent=vecs[a];
			flags[b]=1;
		}
		for(i=1;i<=N;i++) if(flags[i]==0) break;
		Node*root=vecs[i];cin>>a>>b;
		vector<int>a1;vector<int>b1;Node*cur=vecs[a];
		while(cur!=root){a1.push_back(cur->value);cur=cur->parent;}
		a1.push_back(root->value);cur=vecs[b];
		while(cur!=root) {b1.push_back(cur->value);cur=cur->parent;}
		b1.push_back(root->value);i=a1.size()-1;j=b1.size()-1;
		while(i>=0&&j>=0)
		{
			if(a1.at(i)!=b1.at(j))
				break;
			i--;j--;
		}
		if(i==-1) cout<<a<<endl;
		else if(j==-1) cout<<b<<endl;
		else cout<<a1.at(i+1)<<endl;
		for(i=1;i<=N;i++)
		{
			delete vecs[i];
			vecs[i]=NULL;
		}
	}
	return 0;
}