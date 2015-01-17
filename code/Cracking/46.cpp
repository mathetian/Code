#include <iostream>
#include <vector>
using namespace std;

struct Node_t{
	struct Node_t *l;
	struct Node_t *r;
	struct Node_t *p;
};

typedef struct Node_t Node;

Node*same(Node*n1, Node*n2)
{
	vector<Node*>nvec1;
	vector<Node*>nvec2;

	while(n1)
	{
		nvec1.push_back(n1);
		n1=n1->p;
	}
	while(n2)
	{
		nvec2.push_back(n2);
		n2=n2->p;
	}

	int i=nvec1.size()-1,j=nvec2.size()-1;
	while(i>=0&&j>=0&&nvec1.at(i)==nvec2.at(j));
	return nvec1.at(i+1);
}

bool cover(Node*root,Node*n)
{
	if(root==NULL) return false;
	if(root==n) return true;
	return cover(root->l,n)||cover(root->r,n);
}
Node*same(Node*n1,Node*n2,Node*root)
{
	if(root==n1||root==n2) return root;
	if(cover(root->l,n1)&&cover(root->r,n2))
		return same(n1,n2,root->l);
	if(cover(root->r,n1)&&cover(root->r,n2))
		return same(n1,n2,root->r);
	return root;
}