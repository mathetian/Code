#include <iostream>
using namespace std;

struct Node_t{
	struct Node_t *l;
	struct Node_t *r;
	struct Node_t *p;
};

typedef struct Node_t Node;

Node*getFirst(Node*node)
{
	if(!node||node->l==NULL) return node;
	return getFirst(node->l);
}

Node*getNext(Node*node)
{
	Node*root;
	if(!node) return NULL;
	if(node->p==NULL&&node->r) return getFirst(node->r);
	while((root=node->p)!=NULL && root->r==node) node=root;
	return root; 
}