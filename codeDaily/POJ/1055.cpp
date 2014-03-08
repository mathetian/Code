#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char input[100];
char codes[100000][6];int codeNum;int numIndex[100000];
char invalid[100000][10];int invNum;

int cmp(const void*v1,const void*v2)
{
	char*v11=(char*)v1;char*v22=(char*)v2;
	return strcmp(v11,v22);
}

void Divide()
{
	qsort(codes,codeNum,6,cmp);
	for(int i=0;i<codeNum;i++)
		numIndex[i]=1;
	int i,j,k=0;
	for(i=0;i<codeNum;)
	{
		for(j=i+1;j<codeNum;j++)
		{
			if(strcmp(codes[i],codes[j]))
				break;
		}
		strcpy(codes[k],codes[i]);
		numIndex[k++]=j-i;
		i=j;
	}
	if(i<codeNum)
	{
		strcpy(codes[k],codes[i]);
		numIndex[k++]=1;
	}
	codeNum=k;
}

void sortS()
{
	int i,j;int k=0;
	for(i=0;i<codeNum;i++)
	{
		if(numIndex[i]!=0)
		{
			strcpy(codes[k],codes[i]);numIndex[k++]=numIndex[i];
		}
	}
	codeNum=k;
	for(i=0;i<codeNum;)
	{
		int tmp2=numIndex[i];
		for(j=i+1;j<codeNum;j++)
		{
			if(codes[i][0]==codes[j][0]&&codes[i][1]==codes[j][1]&&codes[i][2]==codes[j][2])
			{
				tmp2+=numIndex[j];
			}
			else
				break;
		}
		if(tmp2>=10)
		{
			numIndex[i]=tmp2;
			for(k=i+1;k<j;k++)
				numIndex[k]=0;

		}
		i=j;
	}
	k=0;
	for(i=0;i<codeNum;i++)
	{
		if(numIndex[i]!=0)
		{
			strcpy(codes[k],codes[i]);numIndex[k++]=numIndex[i];
		}
	}
	codeNum=k;
}

int main()
{
	invNum=0;codeNum=0;int bun=0;int lss=0;
	while(scanf("%s",input)!=EOF&&strcmp(input,"000"))
	{
		int len=strlen(input);
		if(len!=5)
		{
			int i;
			for(i=0;i<invNum;i++)
			{
				if(strcmp(invalid[i],input)==0)
					break;
			}
			if(i==invNum)
				strcpy(invalid[invNum++],input);
			continue;
		}
		int i;int zeroNum=0;
		for(i=0;i<5;i++)
		{
			if(input[i]<'0'||input[i]>'9')
				break;
			else if(input[i]=='0')
				zeroNum++;
		}
		if(i<5||zeroNum==5)
		{
			if(invNum==6)
				while(0);
			int j;
			for(j=0;j<invNum;j++)
			{
				if(strcmp(invalid[j],input)==0)
					break;
			}
			if(j==invNum)
				strcpy(invalid[invNum++],input);
			continue;
		}
		strcpy(codes[codeNum++],input);
	}
	lss=codeNum;
	Divide();
//	printf("ZIP         LETTERS     BUNDLES\n\n");
	printf("ZIP         LETTERS     BUNDLES\n\n");
	for(int i=0;i<codeNum;i++)
	{
		if(numIndex[i]<10)
			continue;
		printf("%s         %3d          %2d\n",codes[i],numIndex[i],(int)ceil(numIndex[i]/15.0));
		bun+=(int)ceil(numIndex[i]/15.0);
		numIndex[i]=0;
	}
	putchar('\n');
	sortS();
	for(int i=0;i<codeNum;i++)
	{
		if(numIndex[i]>=10)
		{
			printf("%c%c%cxx         %3d          %2d\n",codes[i][0],codes[i][1],codes[i][2],numIndex[i],(int)ceil(numIndex[i]/15.0));
			bun+=(int)ceil((double)numIndex[i]/15.0);
			numIndex[i]=0;
		}
	}
	putchar('\n');
	for(int i=0;i<codeNum;i++)
	{
		if(numIndex[i]!=0)
		{
			printf("%s         %3d           0\n",codes[i],numIndex[i]);
		}
	}
	putchar('\n');
	printf("TOTALS        %3d          %2d\n",lss,bun);
	putchar('\n');
	printf("INVALID ZIP CODES\n\n");
	for(int i=0;i<invNum;i++)
		printf("%s\n",invalid[i]);
	return 0;
}