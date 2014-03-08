#include<stdio.h>
#include<string.h>

char dict[10000][18];int dictNum;
int lenDict[10000];

int replace(char*res,char*org,int len)
{
	for(int i=0;i<len;i++)
	{
		if(res[i]!=org[i])
		{
			res[i]=org[i];
			if(strcmp(res,org)==0)
				return 1;
			else
				return 0;
		}
	}
}

int add(char*res,char*org,int resLen)
{
	for(int i=0;i<resLen;i++)
	{
		if(res[i]!=org[i])
		{
			for(int j=resLen;j>=i;j--)
				res[j+1]=res[j];
			res[i]=org[i];
			if(strcmp(res,org)==0)
				return 1;
			else
				return 0;
		}
	}
	res[resLen]=org[resLen];
	res[resLen+1]='\0';
	if(strcmp(res,org)==0)
		return 1;
	else
		return 0;
}

int del(char*res,char*org,int resLen)
{
	for(int i=0;i<resLen;i++)
	{
		if(res[i]!=org[i])
		{
			for(int j=i+1;j<=resLen;j++)
				res[j-1]=res[j];
			if(strcmp(res,org)==0)
				return 1;
			else 
				return 0;
		}
	}
}

int main()
{
	char input[18];
	while(scanf("%s",input)&&strcmp(input,"#")!=0)
	{	
		strcpy(dict[dictNum],input);lenDict[dictNum]=strlen(dict[dictNum]);dictNum++;
	}
	while(scanf("%s",input)&&strcmp(input,"#")!=0)
	{
		int len=strlen(input);int i;
		for(i=0;i<dictNum;i++)
		{
			if(strcmp(input,dict[i])==0)
			{
				printf("%s is correct\n",input);break;
			}
		}
		if(i<dictNum)
			continue;
		printf("%s:",input);char tmp[18];strcpy(tmp,input);
		for(i=0;i<dictNum;i++)
		{
			if(lenDict[i]==len)
			{
				if(replace(input,dict[i],len)==1)
					printf(" %s",dict[i]);
			}
			else if(lenDict[i]==len+1)
			{
				if(add(input,dict[i],len)==1)
					printf(" %s",dict[i]);
			}
			else if(lenDict[i]==len-1)
			{
				if(del(input,dict[i],len)==1)
					printf(" %s",dict[i]);
			}
			strcpy(input,tmp);
		}
		putchar('\n');
	}
	return 0;
}