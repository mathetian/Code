#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define FILE 0
#define DIR 1

typedef struct NODE{
	struct NODE*first;struct NODE*next;
	int type;char val[20];
}NODE;
char input[10];char tmp[100][20];

int processDIR(NODE*root)
{
	NODE*n1=root->first;
	while(scanf("%s",input))
	{
		if(strcmp(input,"]")==0||strcmp(input,"*")==0)
			return 0;
		if(strcmp(input,"#")==0)
			return -1;
		NODE*newN=new NODE;newN->first=newN->next=NULL;strcpy(newN->val,input);
		if(n1==NULL)
		{
			root->first=newN;n1=newN;
		}
		else
		{
			n1->next=newN;n1=newN;
		}
		if(input[0]=='f')
			newN->type=FILE;
		else
		{
			newN->type=DIR;
			processDIR(newN);
		}
	}
	
}

int cmp(const void*v1,const void*v2)
{
	return strcmp((char*)v1,(char*)v2);
}
void visit(NODE*root,int depth)
{
	for(int i=0;i<depth;i++)
	{
		printf("|     ");
	}
	printf("%s\n",root->val);
	if(root->type==DIR)
	{
		NODE*n1=root->first;
		while(n1!=NULL)
		{
			if(n1->type==DIR)
				visit(n1,depth+1);
			n1=n1->next;
		}
		n1=root->first;
		int num=0;
		while(n1!=NULL)
		{
			if(n1->type==FILE)
				strcpy(tmp[num++],n1->val);
			n1=n1->next;
		}
		qsort(tmp,num,20,cmp);
		for(int i=0;i<num;i++)
		{
			for(int i=0;i<depth;i++)
				printf("|     ");
			printf("%s\n",tmp[i]);
		}
	}
}

int main()
{
	int index=1;
	while(1)
	{
		NODE*root;
		root=new NODE;root->first=root->next=NULL;strcpy(root->val,"ROOT");root->type=DIR;
		if(processDIR(root)==-1)
			break;
		printf("DATA SET %d:\n",index++);
		visit(root,0);
		putchar('\n');
	}
	return 0;
}