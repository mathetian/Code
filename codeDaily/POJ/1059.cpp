#include<stdio.h>
#include<string.h>

#define NORMAL 0
#define UP 1
#define DOWN 2
#define STOP 3
#define NEXT 4

typedef struct{
	int type;
	int end;
}NODE;

NODE nodes[1100];
int steps[1100];int stpNum;int nowPos[10];

int change(int pos)
{
	if(nodes[pos].type==UP||nodes[pos].type==DOWN)
	{
		return change(nodes[pos].end);
	}
	else
		return pos;
}

int main()
{
	stpNum=0;
	int input;
	while(scanf("%d",&input)&&input!=0)
		steps[stpNum++]=input;
	int playerNum;
	while(scanf("%d",&playerNum)&&playerNum!=0)
	{
		memset(nodes,0,sizeof(int)*1100);
		int first;int second;
		while(scanf("%d%d",&first,&second))
		{
			if(first==0&&second==0)
				break;
			if(second>first)
			{
				nodes[first].type=UP;nodes[first].end=second;
			}
			else
			{
				nodes[first].type=DOWN;nodes[first].end=second;
			}
		}
		while(scanf("%d",&first)&&first!=0)
		{
			if(first>0)
				nodes[first].type=NEXT;
			else
				nodes[0-first].type=STOP;
		}
		memset(nowPos,0,sizeof(int)*10);
		int nowTurn=0;int nowPlayer=0;int mis[10];
		memset(mis,0,sizeof(int)*10);
		while(1)
		{
			if(mis[nowPlayer]!=0)
			{
				mis[nowPlayer]--;
				nowPlayer=(nowPlayer+1)%playerNum;
				continue;
			}
			if(nowPos[nowPlayer]+steps[nowTurn]<100)
			{
				nowPos[nowPlayer]=nowPos[nowPlayer]+steps[nowTurn++];
				nowPos[nowPlayer]=change(nowPos[nowPlayer]);
				if(nodes[nowPos[nowPlayer]].type==NEXT)
					continue;
				else if(nodes[nowPos[nowPlayer]].type==STOP)
					mis[nowPlayer]++;
			}
			else if(nowPos[nowPlayer]+steps[nowTurn]==100)
			{
				printf("%d\n",nowPlayer+1);break;
			}
			else
			{
				nowTurn++;
			}
			nowPlayer=(nowPlayer+1)%playerNum;
		}
	}
	return 0;
}