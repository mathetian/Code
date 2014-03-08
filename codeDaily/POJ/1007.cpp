#include<stdio.h>
#include<string.h>

char tmp[101][51];int num[101];int len2,nums;int order[101];
void sortKind()
{
	int i,j;char tmp4[51];
	for(i=1;i<nums;i++)
	{
		int tmp3=num[i];
		strcpy(tmp4,tmp[i]);
		for(j=i-1;j>=0;j--)
		{
			if(tmp3<num[j])
			{
				strcpy(tmp[j+1],tmp[j]);
				num[j+1]=num[j];
			}
			else
				break;
		}
		strcpy(tmp[j+1],tmp4);
		num[j+1]=tmp3;	
	}
}

int main()
{
	
	scanf("%d%d",&len2,&nums);
	char d[51];int i;
	for(i=0;i<nums;i++)
	{
		scanf("%s",tmp[i]);
		int len=strlen(tmp[i]);
		num[i]=0;
		for(int j=0;j<len-1;j++)
		{
			int k=j+1;
			while(k<len)
			{
				if(tmp[i][j]>tmp[i][k])
					num[i]+=1;
				k++;
			}
		}
	}
	sortKind();
	for(int i=0;i<nums;i++)
	{
		printf("%s\n",tmp[i]);
	}
	return 0;
}