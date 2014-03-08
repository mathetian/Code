#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char codes[20][20];int codeNum;
char input[20];

int cmp(const void*v1,const void*v2)
{
	int len1=strlen((char*)v1);int len2=strlen((char*)v2);
	if(len1<len2)
		return -1;
	else if(len1==len2)
		return 0;
	else
		return 1;
}

int main()
{
	int index=1;
	while(scanf("%s",input)!=EOF)
	{
		strcpy(codes[0],input);codeNum=1;
		while(scanf("%s",input)&&input[0]!='9')
			strcpy(codes[codeNum++],input);
		qsort(codes,codeNum,20,cmp);
		int i,j;int k;int flag=0;
		for(i=0;i<codeNum;i++)
		{
			int len=strlen(codes[i]);
			for(j=i+1;j<codeNum;j++)
			{
				for(k=0;k<len;k++)
				{
					if(codes[i][k]!=codes[j][k])
						break;
				}
				if(k==len)
				{
					flag=1;goto label1;
				}
			}
		}
label1:;
		if(flag==1)
			printf("Set %d is not immediately decodable\n",index++);
		else
			printf("Set %d is immediately decodable\n",index++);
	}
	return 0;
}