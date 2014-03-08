#include<stdio.h>
#include<string.h>

typedef struct{
	char below[10];int score;int flag;
}PART;

PART parts[15];

int main()
{
	char name[13];int rBalls[30];
	while(scanf("%s",name)!=EOF)
	{
		int num=0;
		while(scanf("%d",&rBalls[num++])&&rBalls[num-1]!=-1);
		num--;
		int nowIndex=0;
		int flag=0;int oldScore=0;int pairNum=0;
		memset(parts,0,sizeof(PART)*15);

		for(nowIndex=0;nowIndex<num;nowIndex++)
		{
			if(pairNum==10)
				break;
			if(pairNum==4)
				while(0);
			if(rBalls[nowIndex]==0)
			{

				if(flag==1)
				{
					if(rBalls[nowIndex-1]!=10)
						parts[pairNum].below[0]=10-rBalls[nowIndex-1]+'0';
					else
						parts[pairNum].below[0]='-';
					parts[pairNum].below[1]='/';
					if(nowIndex==num-1)
						parts[pairNum].flag=0;
					else
					{
						if(nowIndex==num-2&&pairNum==9)
						{
							if(rBalls[nowIndex+1]==0)
								parts[pairNum].below[2]='X';
							else if(rBalls[nowIndex+1]==10)
								parts[pairNum].below[2]='-';
							else
								parts[pairNum].below[2]=10-rBalls[nowIndex+1]+'0';
						}
						parts[pairNum].flag=1;
						parts[pairNum].score=20-rBalls[nowIndex+1]+oldScore;
						oldScore=parts[pairNum].score;
					}
					pairNum++;
					flag=0;
				}
				else
				{
					if(pairNum==9)
						while(0);
						parts[pairNum].below[0]='X';
						if(nowIndex==num-1)
							parts[pairNum++].flag=0;
						else if(nowIndex==num-2)
						{
							parts[pairNum].flag=0;
							if(pairNum!=9)
							{
								pairNum++;continue;
							}
							if(rBalls[nowIndex+1]==0)
								parts[pairNum].below[1]='X';
							else if(rBalls[nowIndex+1]==10)
								parts[pairNum].below[1]='-';
							else
								parts[pairNum].below[1]=10-rBalls[nowIndex+1]+'0';
							pairNum++;
						}
						else
						{
							parts[pairNum].flag=1;
							parts[pairNum].score=oldScore+10;
							if(rBalls[nowIndex+1]==0)
								parts[pairNum].score+=10+10-rBalls[nowIndex+2];
							else
								parts[pairNum].score+=10-rBalls[nowIndex+2];
							oldScore=parts[pairNum].score;
							if(pairNum!=9)
							{
								pairNum++;continue;
							}
							if(rBalls[nowIndex+1]==0)
								parts[pairNum].below[1]='X';
							else if(rBalls[nowIndex+1]==10)
								parts[pairNum].below[1]='-';
							else
								parts[pairNum].below[1]=10-rBalls[nowIndex+1]+'0';

							if(rBalls[nowIndex+2]==0&&rBalls[nowIndex+1]==0)
								parts[pairNum].below[2]='X';
							else if(rBalls[nowIndex+2]==0)
								parts[pairNum].below[2]='/';
							else if(rBalls[nowIndex+2]==10)
								parts[pairNum].below[2]='-';
							else if(rBalls[nowIndex+2]>=1&&rBalls[nowIndex+2]<=9&&rBalls[nowIndex+1]==0)
								parts[pairNum].below[2]=10-rBalls[nowIndex+2]+'0';
							else
								parts[pairNum].below[2]=rBalls[nowIndex+1]-rBalls[nowIndex+2]+'0';
							pairNum++;
						}
						
				}
			}
			else
			{
				if(flag==0)
					flag=1;
				else
				{
					parts[pairNum].flag=1;
					if(rBalls[nowIndex-1]==10)
						parts[pairNum].below[0]='-';
					else
						parts[pairNum].below[0]=10-rBalls[nowIndex-1]+'0';
					if(rBalls[nowIndex]==rBalls[nowIndex-1])
						parts[pairNum].below[1]='-';
					else
						parts[pairNum].below[1]=rBalls[nowIndex-1]-rBalls[nowIndex]+'0';
					parts[pairNum].score=10-rBalls[nowIndex]+oldScore;
					oldScore=parts[pairNum].score;
					pairNum++;
					flag=0;
				}
			}
		}
		if(pairNum!=10&&flag==1)
		{
			parts[pairNum].below[0]=10-rBalls[num-1]+'0';
			parts[pairNum].flag=0;
			pairNum++;
		}
	//	for(int i=1;i<10;i++)
	//			printf("%d",i);
	//	for(int j=0;j<5;j++)
	//		for(int i=0;i<10;i++)
	//			printf("%d",i);
	//	putchar('\n');
		printf("%s",name);
		int len=strlen(name);
		for(int i=len;i<13;i++)
			putchar(' ');
		for(int i=0;i<pairNum;i++)
		{	
			printf("%-3s ",parts[i].below);
		}
		putchar('\n');
		for(int i=0;i<13;i++)
			putchar(' ');
		for(int i=0;i<pairNum;i++)
		{
			if(parts[i].flag==0)
				printf("    ");
			else
				printf("%3d ",parts[i].score);
		}
		printf("\n\n");
	}
	return 0;
}