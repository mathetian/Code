#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char t1[3][12];
char t2[3][12];
//int flag2[3];
/*
	heavy:1 light -1
*/
int main()
{
	int flag[12];int times[12];
	int cases;
	scanf("%d",&cases);
	//char t1[12];char t2[12];
	char res[12];
	while(cases--)
	{
	//	memset(flag,0,sizeof(int)*12);
		for(int i=0;i<12;i++)
		{
			flag[i]=-2;times[i]=0;
		}
		for(int i=0;i<3;i++)
		{
			scanf("%s%s%s",t1[i],t2[i],res);
			int len1=strlen(t1[i]);int len2=strlen(t2[i]);
			if(strcmp(res,"even")==0)
			{
				for(int j=0;j<len1;j++)
				{
					flag[t1[i][j]-'A']=0;
				}
				for(int j=0;j<len2;j++)
				{
					flag[t2[i][j]-'A']=0;
				}
			}
			else if(strcmp(res,"up")==0)
			{
				for(int j=0;j<len1;j++)
				{
					if(flag[t1[i][j]-'A']!=0)
						if(flag[t1[i][j]-'A']!=1)
						{
							flag[t1[i][j]-'A']=-1;times[t1[i][j]-'A']++;
						}
						else
							flag[t1[i][j]-'A']=0;
				}
				for(int j=0;j<len2;j++)
				{
					if(flag[t2[i][j]-'A']!=0)
						if(flag[t2[i][j]-'A']!=-1)
						{
							flag[t2[i][j]-'A']=1;times[t2[i][j]-'A']++;
						}
						else
							flag[t2[i][j]-'A']=0;
				}
			}
			else 
			{
				for(int j=0;j<len1;j++)
				{
					if(flag[t1[i][j]-'A']!=0)
						if(flag[t1[i][j]-'A']!=-1)
						{
							flag[t1[i][j]-'A']=1;times[t1[i][j]-'A']++;
						
						}
						else
							flag[t1[i][j]-'A']=0;
				}
				for(int j=0;j<len2;j++)
				{
					if(flag[t2[i][j]-'A']!=0)
						if(flag[t2[i][j]-'A']!=1)
						{
							flag[t2[i][j]-'A']=-1;
							times[t2[i][j]-'A']++;
						}
						else
							flag[t2[i][j]-'A']=0;
				}
			}
		}
		int num=-1;//int num2=0;
		for(int i=0;i<12;i++)
		{
			if(flag[i]!=0&&flag[i]!=-2)
			{
				num=i;break;
			}
		}
		int max2=times[num];
		for(int i=0;i<12;i++)
		{
			if((flag[i]!=0)&&(flag[i]!=-2)&&(times[i]>max2))
			{
				num=i;max2=times[num];
			}
		}
		if(num!=-1)
		{
			printf("%c is the counterfeit coin and it is ",num+'A');
			if(flag[num]!=1)
			{
				printf("heavy.\n");
			}
			else
			{
				printf("light.\n");
			}
		}
		
	}
	return 0;
}