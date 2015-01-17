/**
	What's wrong with this problem ?
	https://sites.google.com/site/spaceofjameschen/home/linked-list/cut-off-circular-linked-list-node
**/

#include <iostream>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

struct Node_t
{
	struct Node_t *next;
	int val;
};

typedef struct Node_t Node;

Node* findcycle(Node*head)
{
	if(!head||!head->next||!head->next->next) return NULL;
	if(head->next==head) return head;
	
	Node*a=head->next,*b=head->next->next; 

	while(b&&a!=b&&(a=a->next)&&(b=b->next->next)); 

	if(!b) return NULL; a=head; while(a!=b)
	{ a=a->next;b=b->next; }
	
	return b;
}

Node* Initialization(int n,int k)
{
	Node*head=new Node;
	head->val=0;Node*cur=head;Node*tail=cur;
	for(int i=1;i<n;i++)
	{
		cur->next=new Node;
		cur->next->val=i;
		cur=cur->next;
		tail=cur;
	}
	cur=head;
	for(int i=0;i<k;i++,cur=cur->next);
	tail->next=cur;
	return head;
}

void DoTest()
{
	Node*head=Initialization(10,4);
	ASS_EQUAL(findcycle(head)->val,4);
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;
	return 0;
}