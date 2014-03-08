
#include<stdio.h>
#include<string.h>

#define MAXN 500000
#define MAXHASHSIZE  1000003

int xDir[]={-1,1,0,0};
int yDir[]={0,0,-1,1};
char*dirFlag="udlr";

char maps[MAXN][9];
int pos[MAXN];
int rear,front;
int parents[MAXN];int dir[MAXN];
int head[MAXHASHSIZE], next[MAXN];

int hash(int index)
{
	int num=0;
	for(int i=0;i<9;i++)
		num=num*10+maps[index][i]-'0';
	return num%MAXHASHSIZE;
}

int able(int x,int y,int dir)
{
	int ex=x+xDir[dir];int ey=y+yDir[dir];
	if(ex>=0&&ex<3&&ey>=0&&ey<3)
		return 1;
	else
		return 0;
}

void print(char*msp)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			printf("%c ",msp[i*3+j]);
		putchar('\n');
	}
	putchar('\n');
	putchar('\n');
}

int try_insert(int index)
{
	int has=hash(index);
	int u=head[has];
	while(u)
	{
		if(memcmp(maps[u],maps[index],9)==0)
			return 0;
		u=next[u];
	}
	next[index]=head[has];
	head[has]=index;
	return 1;
}

int bfs()
{
	//int endHash=0;
	//for(int i=1;i<9;i++)
	//	endHash=endHash*10+i;
//	endHash*=10;
//	endHash%=MAXHASHSIZE;
	char*goal="123456780";
	front=0;rear=1;

	memset(head,0,sizeof(int)*MAXHASHSIZE);
	memset(next,0,sizeof(int)*MAXHASHSIZE);

	while(front<rear)
	{
	//	printf("(%d,%d)\n",front,rear);
		//if(front==1&&rear==4)
		//	while(0);
		if(memcmp(maps[front],goal,9)==0)
			return 1;
	//	print(maps[front]);
		for(int i=0;i<4;i++)
		{
			if(able(pos[front]/3,pos[front]%3,i)==1)
			{
				char tmp2[9];memcpy(tmp2,maps[front],9);
				int indx=pos[front]/3;int indy=pos[front]%3;
				int ninx=indx+xDir[i];int niny=indy+yDir[i];
				int nfront=ninx*3+niny;
				int ofront=pos[front];
				char tmp=tmp2[ofront];tmp2[ofront]=tmp2[nfront];tmp2[nfront]=tmp;
				memcpy(maps[rear],tmp2,9);
				if(try_insert(rear))
				{
					//memcpy(maps[rear],tmp2,9);
					parents[rear]=front;dir[rear]=dirFlag[i];
					pos[rear]=nfront;
					rear++;
				}
			}
		}
		front++;
	}

	return 0;
}

void print(int front)
{
	if(front!=0)
	{
		print(parents[front]);
		printf("%c",dir[front]);
	}
}

int main()
{
	char str[30];
	while(gets(str))
	{
		int i;int len=strlen(str);
		int indX=0;int indY=0;
		for(i=0;i<len;i++)
		{
			if(str[i]!=' ')
			{
				if(str[i]=='x')
				{	
					maps[0][indX*3+indY]='0';
					pos[0]=indX*3+indY;
				}
				else
					maps[0][indX*3+indY]=str[i];
				if(indY==2)
				{
					indX++;indY=0;
				}
				else
					indY++;
			}
			
		}
		front=0;rear=1;
		if(bfs()==0)
			puts("unsolvable");
		else
			print(front);
		getchar();
	}
	return 0;
}
