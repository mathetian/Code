#include <iostream>
#include <string>
using namespace std;

#include <string.h>

struct Node_t
{
	int data;
	struct Node_t *next;
};
typedef struct Node_t Node;

Node* nthToLast(Node*head,int n)
{
	Node*cur=head;
	while(n-->0&&cur) cur=cur->next;
	if(cur == NULL) return NULL;
	Node*cur2=head;
	while(cur2&&cur)
	{
		cur2=cur2->next;
		cur=cur->next;
	}
	return cur2;
}

Node*findBeginNode(Node*head)
{
    Node*h1=head;
    Node*h2=h1;
    while(h2&&h2->next)
    {
        h1=h1->next;
        h2=h2->next->next;
        if(h1==h2)
            break;
    }
    if(!h2||!h2->next)
        return NULL;
    h1=head;
    while(h1!=h2)
    {
        h1=h1->next;
        h2=h2->next;
    }
    return h1;
}

int main()
{
	return 0;
}