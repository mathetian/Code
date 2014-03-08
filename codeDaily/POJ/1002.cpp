
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define N 100001
#define M 11
char tmp[N][100];

int cmp(const void*v1,const void*v2)
{
	return strcmp((char*)v1,(char*)v2);
}

int main()
{
	int num;
	scanf("%d",&num);
	char str[100];
	char result[100];
	int num2=0;
	while(num--)
	{
		scanf("%s",str);
		memset(result,'\0',20);int index=0;
		int len=strlen(str);
		
		for(int i=0;i<len;i++)
		{
			if(index==3)
			{
				result[3]='-';
				index++;
			}
			if(str[i]>='0'&&str[i]<='9')
			{
				result[index++]=str[i];
			}
			else if(str[i]>='A'&&str[i]<='Z')
			{
				if(str[i]>='A'&&str[i]<='C')
					result[index++]='2';
				else if(str[i]>='D'&&str[i]<='F')
					result[index++]='3';
				else if(str[i]>='G'&&str[i]<='I')
					result[index++]='4';
				else if(str[i]>='J'&&str[i]<='L')
					result[index++]='5';
				else if(str[i]>='M'&&str[i]<='O')
					result[index++]='6';
				else if(str[i]>='P'&&str[i]<='S')
					result[index++]='7';
				else if(str[i]>='T'&&str[i]<='V')
					result[index++]='8';
				else if(str[i]>='W'&&str[i]<='Y')
					result[index++]='9';
			}
		}
		result[8]='\0';
		strcpy(tmp[num2++],result);
	}
	qsort(tmp,num2,100,cmp);int flag=0;
	int prev=0;int i;
	for(i=1;i<num2;i++)
	{
		if(strcmp(tmp[prev],tmp[i])!=0)
		{
			if(i-prev>1)
			{
				printf("%s %d\n",tmp[prev],i-prev);
				flag=1;
			}
			prev=i;
		}
	}
	if(prev!=num2-1)
	{
		printf("%s %d\n",tmp[prev],num2-prev);
		flag=1;
	}
	if(flag==0)
	{
		printf("No duplicates."); 
	}
	return 0;
}
