#include<stdio.h>
#include<string.h>

#define EMPTY 0
#define NEMPTY 1

typedef struct{
//	int val;
	int nowPos;int destPos;
}PIECE;
int cluNum;int filesNum;int index=1;int rightPos=0;
PIECE posVal[10001];

int empty[10001];

int main()
{
	
	scanf("%d%d",&cluNum,&filesNum);
	memset(posVal,0,sizeof(PIECE)*10001);
	memset(empty,0,sizeof(int)*10001);
	while(filesNum--)
	{
		int fileNum;scanf("%d",&fileNum);
		for(int i=0;i<fileNum;i++)
		{
			int tmp;scanf("%d",&tmp);
			posVal[index].destPos=index;posVal[index].nowPos=tmp;
			if(index==tmp)
				rightPos++;
			index++;
			empty[tmp]=NEMPTY;
		}
	}
	index-=1;
	if(rightPos==index)
	{
		printf("No optimization needed\n");return 0;
	}
	int stPos=1;int iNowPos;
	while(rightPos!=index)
	{
		int selPos=1;
		for(selPos=stPos;selPos<=index;selPos++)
		{
			if(empty[selPos]==EMPTY)
			{
				for(iNowPos=1;iNowPos<=index;iNowPos++)
				{
					if(posVal[iNowPos].destPos==selPos)
						break;
				}
				if(iNowPos<=index)
				{
					empty[selPos]=NEMPTY;empty[posVal[iNowPos].nowPos]=EMPTY;
					printf("%d %d\n",posVal[iNowPos].nowPos,posVal[iNowPos].destPos);
					posVal[iNowPos].nowPos=selPos;
					rightPos++;break;
				}
			}
		}
		if(selPos>index)
		{
			selPos=cluNum;
			for(iNowPos=1;iNowPos<=index;iNowPos++)
			{
				if(posVal[iNowPos].destPos!=posVal[iNowPos].nowPos&&posVal[iNowPos].nowPos<=index)
				{
					printf("%d %d\n",posVal[iNowPos].nowPos,selPos);
					empty[posVal[iNowPos].nowPos]=EMPTY;
					posVal[iNowPos].nowPos=selPos;
					empty[selPos]=NEMPTY;break;
				}
			}
		}
	}
	
	return 0;
}