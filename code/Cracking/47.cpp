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

bool cmp(Node*n1,Node*n2)
{
	if(!n1&&!n2) return true;
	if((n1&&!n2)||(!n1&&n2)) return false;
	if(n1->data!=n2->data) return false;
	if(cmp(n1->l,n2->l)&&cmp(n1->r,n2->r)) return true;
	return false;
}

bool flag = false;
void cmpsub(Node*n1,Node*n2)
{
	if(flag==true) return;
	if(!n1) return;
	if(n1->data==n2->data)
		flag = cmp(n1,n2);
	cmpsub(n1->l, n2);
	cmpsub(n1->r, n2);
}