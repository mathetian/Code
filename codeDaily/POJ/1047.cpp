#include<stdio.h>
#include<string.h>

char val[100];char result[100];int orgLen;int flag;

void reverse(char*t1)
{
	int len=strlen(t1);
	int half=len/2;
	for(int i=0;i<half;i++)
	{
		char tmp2=t1[i];
		t1[i]=t1[len-1-i];
		t1[len-1-i]=tmp2;
	}
}

int multi(char*orgi,int times,char*result)
{
	memset(result,'\0',100);
	int len=strlen(orgi);reverse(orgi);
	int remain=0;
	for(int i=0;i<len;i++)
	{
		int asd=(orgi[i]-'0')*times+remain;
		result[i]=asd%10+'0';remain=asd/10;
	}
	reverse(orgi);
	if(remain!=0)
		return 0;
	result[len]='\0';
	reverse(result);
	return 1;
}

int main()
{
	while(scanf("%s",val)!=EOF)
	{
		orgLen=strlen(val);flag=0;
		int i;int j;int k;
		for(i=2;i<=orgLen&&flag==0;i++)
		{
			if(multi(val,i,result)==0)
			{
				flag=1;continue;
			}
			for(j=0;j<orgLen;j++)//判断右移j位能否得到答案
			{
				for(k=0;k<orgLen;k++)
				{
					if(val[k]!=result[(k+j)%orgLen])
						break;
				}
				if(k==orgLen)//get what needed
					break;
			}
			if(j==orgLen)
				flag=1;
		}
		printf("%s is ",val);
		if(flag==1)
			printf("not cyclic\n");
		else
			printf("cyclic\n");
	}
	return 0;
}