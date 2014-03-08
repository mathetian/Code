#include<stdio.h>

int data[1001];int num=0;

int main()
{
	int total=0;int input;
	scanf("%d",&input);int k=1;
	while(total<input)
	{
		k++;
		total+=k;
		data[num++]=k;
	}

	if(total==input)
	{
		for(int i=0;i<num;i++)
		{
			printf("%d ",data[i]);
		}
	}
	else if(total>input)
	{
		total=total-data[num-1];num--;
		for(int i=num-1;;i--)
		{
			if(i==-1)
				i=num-1;
			total+=1;data[i]+=1;
			if(total==input)
			{
				for(int i=0;i<num;i++)
				{	printf("%d ",data[i]);}
				break;
			}
		}
	}
	return 0;
}