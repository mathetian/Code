#include<stdio.h>
#include<string.h>

int Catalan[]={1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700};

typedef struct NODE{
	struct NODE*left;
	struct NODE*right;
	int numLeft;int numRight;
	int numTotal;
	NODE()
	{
		left=NULL;right=NULL;
		numTotal=numLeft=numRight=0;
	}
};

int sum[20];int size;
int getLRnUM(int val,int&leftNum,int&rightNum,int nodeNum)
{
	leftNum=0;rightNum=nodeNum;
	int tmpSum=0;int oldtmp;
	while(1)
	{
		oldtmp=tmpSum;
		if(leftNum==0)
			tmpSum+=Catalan[rightNum-1];
		else if(rightNum==0)
			tmpSum+=Catalan[leftNum-1];
		else
			tmpSum=tmpSum+Catalan[leftNum-1]*Catalan[rightNum-1];
		if(tmpSum>=val)
			return oldtmp;
		leftNum++;rightNum--;
	}
}

//NODE*process2(int val,int nodeNum)
//{
//	
//}

NODE* process(int val)
{
	int nodeNum;
	for(nodeNum=1;nodeNum<=size;nodeNum++)
		if(sum[nodeNum]>=val)
			break;
	NODE*now=new NODE;now->numTotal=nodeNum;
	val=val-sum[nodeNum-1];
	nodeNum--;int index=1;
	if(nodeNum==0)
		return now;
	int leftNum;int rightNum;
	int remain=val-getLRnUM(val,leftNum,rightNum,nodeNum);
	now->numRight=rightNum;now->numLeft=leftNum;
	if(leftNum==0)
		/*now->right=process(val);*/
			now->right=process(val+sum[rightNum-1]);
	else if(rightNum==0)
		/*now->left=process(val-sum[nodeNum]);*/
		/*now->left=process(val-sum[nodeNum]+sum[leftNum-1]);*/
		now->left=process(remain+sum[leftNum-1]);
	else
	{
		int rightVal=remain%Catalan[rightNum-1];
		if(rightVal==0)
			rightVal=Catalan[rightNum-1];
		int leftVal=remain/Catalan[rightNum-1];
		if(remain%Catalan[rightNum-1]!=0)
			leftVal++;
		now->right=process(rightVal+sum[rightNum-1]);
		now->left=process(leftVal+sum[leftNum-1]);
	}
	return now;
}

void LMR(NODE*head)
{
	if(head==NULL)
		return;
	if(head->left!=NULL)
	{
		putchar('(');
		LMR(head->left);
		putchar(')');
	}
	putchar('X');
	if(head->right!=NULL)
	{
		putchar('(');
		LMR(head->right);
		putchar(')');
	}
}

int main()
{
	size=sizeof(Catalan)/sizeof(int);
	sum[0]=0;
	for(int i=1;i<=size;i++)
		sum[i]=sum[i-1]+Catalan[i-1];
	int val;
	while(scanf("%d",&val)&&val!=0)
	{
		NODE*head=process(val);
		LMR(head);
		putchar('\n');
	}
	return 0;
}