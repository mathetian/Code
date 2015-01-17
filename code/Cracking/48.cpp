#include <iostream>
#include <vector>
using namespace std;

struct Node_t{
	struct Node_t *l;
	struct Node_t *r;
	struct Node_t *p;
	int data;
};

typedef struct Node_t Node;

int tmp=0;
bool flag=false;
void sum(Node*root,Node*node)
{
	if(flag == true) return;
	if(!root) return;
	tmp += root->data;
	if(root==node) flag = true;
	else
	{
		sum(root->l,node);
		sum(root->r,node);
	}
	if(flag==false)
		tmp -= root->data;
}

int main()
{
	return 0;
}