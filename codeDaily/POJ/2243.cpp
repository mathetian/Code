//#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

#define N 8

typedef struct{
	int x,y;
	int parentx;int parenty;
	int g_score;int f_score;
}POINT;

bool operator<(POINT p1,POINT p2)
{
	return p1.f_score>p2.f_score;
}

vector<POINT>closeSet;
priority_queue<POINT>openSet;
POINT maps[N+1][N+1];

int reconstruct_path(int x,int y)
{
	if(maps[x][y].parentx!=-1)
	{
//		reconstruct_path(maps[x][y].parentx,maps[x][y].parenty);
//		printf("%d%d->%d%d\n",maps[x][y].parentx,maps[x][y].parenty,x,y);
//		return 1;
		return reconstruct_path(maps[x][y].parentx,maps[x][y].parenty)+1;
	}
	return 0;
}

int xDir[]={-1,-2,-1,-2,1,2,1,2};
int yDir[]={-2,-1,2,1,-2,-1,2,1};

int able(POINT now,int index)
{
	int nx=now.x+xDir[index];int ny=now.y+yDir[index];
	if(nx>=0&&nx<N&&ny>=0&&ny<N)
		return 1;
	return 0;
}

int exist_inClose(POINT p2)
{
	for(int i=0;i<closeSet.size();i++)
		if(p2.x==closeSet.at(i).x&&p2.y==closeSet.at(i).y)
			return 1;
	return 0;
}

int exist_open(POINT p2,POINT&p3)
{
	priority_queue<POINT>openSet2=openSet;
	while(!openSet2.empty())
	{
		p3=openSet2.top();openSet2.pop();
		if(p2.x==p3.x&&p2.y==p3.y)
			return 1;
	}
	return 0;
}

int AStar(POINT start,POINT goal)
{
	maps[start.x][start.y].parentx=-1;
	maps[start.x][start.y].parenty=-1;
	maps[start.x][start.y].g_score=0;
	maps[start.x][start.y].f_score=abs(start.x-goal.x)+abs(start.y-goal.y);
	start.g_score=0;start.f_score=maps[start.x][start.y].f_score;
	closeSet.clear();
	while(!openSet.empty()) 
		openSet.pop();
	openSet.push(start);
	while(!openSet.empty())
	{
		POINT p1=openSet.top();
		if(p1.x==goal.x&&p1.y==goal.y)
			return reconstruct_path(goal.x,goal.y);
		openSet.pop();
		closeSet.push_back(p1);
		for(int index=0;index<8;index++)
		{
			if(able(p1,index)==1)
			{
				POINT p2={p1.x+xDir[index],p1.y+yDir[index]};
				if(exist_inClose(p2))
					continue;
				int tentative_g_score=p1.g_score+abs(p1.x-p2.x)+abs(p1.y-p2.y);
				POINT p3;
				if(exist_open(p2,p3)==0||tentative_g_score<p3.g_score)
				{
					p2.g_score=tentative_g_score;
					p2.f_score=tentative_g_score+abs(p2.x-goal.x)+abs(p2.y-goal.y);;
					openSet.push(p2);

					maps[p2.x][p2.y].g_score=tentative_g_score;
					maps[p2.x][p2.y].f_score=p2.f_score;
					maps[p2.x][p2.y].parentx=p1.x;maps[p2.x][p2.y].parenty=p1.y;
				}
			}
		}
	}
	return -1;
}
int main()
{
	char tmp1[5];char tmp2[5];
	while(cin>>tmp1)
	{
		cin>>tmp2;
		POINT start;POINT goal;
		start.x=tmp1[1]-'0'-1;goal.x=tmp2[1]-'0'-1;
		start.y=tmp1[0]-'a';goal.y=tmp2[0]-'a';
		int ways=AStar(start,goal);
		if(ways==-1)
			printf("No\n");
		else
			printf("To get from %s to %s takes %d knight moves.\n",tmp1,tmp2,ways);
	}
	return 0;
}