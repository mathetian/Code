#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

#define EMPTY 0
#define DEBRIS 1
#define OCCUPIED 2
#define HUMAN 3

#define OUTRANGE 1
#define CANAVOID 0
#define DEAD 2

#define DIRS 0
#define SELS 1

typedef struct POINT{
	int x,y;
	int operator==(POINT p1)
	{
		if(x==p1.x&&y==p1.y)
			return 1;
		return 0;
	}
}POINT;

typedef pair<int,POINT> indPot;

typedef struct MARK{
	int robRe;
	int flag;
	int minDist;
	int index;
}MARK;

int maps[50][50];

POINT human;POINT Robots[51];int robNum;int debNum;
POINT lists[2500];int listNum;int listNNow;
int listUsed[2500];
int dir[9][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};MARK marks[10];
int mapcy[50][50];POINT rob2[51];int rob2Num;POINT hDest;int minDist2;int d1;
int derNum;
//#include"main.h"

int cmp(const void*p1,const void*p2)
{
	MARK m1=*(MARK*)p1;
	MARK m2=*(MARK*)p2;
	if(m2.flag!=CANAVOID)
		return 1;
	else if(m1.flag!=CANAVOID)
		return -1;
	if(m1.robRe==m2.robRe)
	{
		if(m1.minDist==m2.minDist)
			return m1.index>m2.index?1:-1;
		else
			return m1.minDist>m2.minDist?-1:1;
	}
	return m1.robRe>m2.robRe?1:-1;
}

int outRange(POINT p1)
{
	if(p1.x>=1&&p1.x<=31&&p1.y>=1&&p1.y<=31)
		return 0;
	return 1;
}

int dist(POINT p1,POINT p2)
{
	return abs(p1.x-p2.x)+abs(p1.y-p2.y);
}

void proHumanDir(int i,int flag3)
{
	
	if(flag3==DIRS)
	{	hDest.x=human.x+dir[i][0];hDest.y=human.y+dir[i][1];}
	else
	{
		hDest.x=lists[i].x;hDest.y=lists[i].y;
	}
	if(outRange(hDest)==1)
	{
		marks[i].flag=OUTRANGE;return;
	}
	else
	{
		mapcy[human.x][human.y]=EMPTY;
		if(mapcy[hDest.x][hDest.y]==DEBRIS)
		{
			POINT nDest={hDest.x+dir[i][0],hDest.y+dir[i][1]};
			if(outRange(nDest)==1||mapcy[nDest.x][nDest.y]==DEBRIS)
			{
				marks[i].flag=OUTRANGE;
				return;
			}
			else if(mapcy[nDest.x][nDest.y]==EMPTY)
				mapcy[nDest.x][nDest.y]=DEBRIS;
			else if(mapcy[nDest.x][nDest.y]==OCCUPIED)
			{
				for(int j=0;j<rob2Num;j++)
				{
					if(nDest==rob2[j])
					{
						for(int k=j+1;k<rob2Num;k++)
							rob2[k-1]=rob2[k];
						rob2Num--;
					//	d1++;
						break;
					}
				}
				mapcy[nDest.x][nDest.y]=DEBRIS;
			}
		}
		else if(mapcy[hDest.x][hDest.y]==OCCUPIED)
		{
			marks[i].flag=OUTRANGE;
			return;
		}
		mapcy[hDest.x][hDest.y]=HUMAN;
	}
}

int latter(int i,int flag4)
{
	vector<indPot>indPV;indPV.clear();
	int flag[60];memset(flag,0,sizeof(int)*60);
	int distMin=1000;
	for(int j=0;j<rob2Num;j++)
	{
		int min=1000;int ind=-1;
		for(int k=0;k<9;k++)
		{
			POINT nPnt={rob2[j].x+dir[k][0],rob2[j].y+dir[k][1]};
			if(dist(nPnt,hDest)<min)
			{
				min=dist(nPnt,hDest);
				ind=k;
			}
		}
		POINT nPnt={rob2[j].x+dir[ind][0],rob2[j].y+dir[ind][1]};
		if(nPnt==hDest)
		{
			marks[i].flag=DEAD;
			if(flag4==SELS)
				while(0);
			return 0;
		}
		distMin=distMin<min?distMin:min;
		if(mapcy[nPnt.x][nPnt.y]==DEBRIS)
		{
			flag[j]=1;
			mapcy[rob2[j].x][rob2[j].y]=EMPTY;
		}
		else
			indPV.push_back(make_pair(j,nPnt));
		if(hDest.x==13&&hDest.y==9&&j==8)
			while(0);
	}
	
	if(flag4==SELS)
		return 1;
	vector<indPot>iV2;iV2.clear();
	for(int j=0;j<indPV.size();j++)
	{
		indPot pot=indPV.at(j);
		if(flag[pot.first]==1)
			continue;
		for(int k=j+1;k<indPV.size();k++)
		{
			indPot pot2=indPV.at(k);
			if(flag[pot2.first]==1)
				continue;
			if(pot2.second==pot.second)
			{
				flag[pot.first]=1;
				flag[pot2.first]=1;
				mapcy[pot.second.x][pot.second.y]=DEBRIS;
				mapcy[rob2[pot.first].x][rob2[pot.first].y]=EMPTY;
				mapcy[rob2[pot2.first].x][rob2[pot2.first].y]=EMPTY;
			}
		}
	if(flag[pot.first]==0)
			iV2.push_back(pot);
	}
		minDist2=1000;
		for(int j=0;j<iV2.size();j++)
		{
			indPot pot=iV2.at(j);
			if(minDist2>dist(pot.second,hDest))
				minDist2=dist(pot.second,hDest);
			mapcy[pot.second.x][pot.second.y]=10;
			if(mapcy[rob2[pot.first].x][rob2[pot.first].y]==10||mapcy[rob2[pot.first].x][rob2[pot.first].y]==DEBRIS)
				continue;
			mapcy[rob2[pot.first].x][rob2[pot.first].y]=EMPTY;
			
		}
		for(int j=0;j<iV2.size();j++)
		{
			indPot pot=iV2.at(j);
			if(mapcy[pot.second.x][pot.second.y]==10)
				mapcy[rob2[pot.first].x][rob2[pot.first].y]=OCCUPIED;
		}
		d1=0;
		for(int j=0;j<rob2Num;j++)
			if(flag[j]==0)
				d1++;
		return 0;
}

void pro(int i)
{
	memcpy(mapcy,maps,2500*sizeof(int));
	memcpy(rob2,Robots,sizeof(POINT)*50);
	rob2Num=robNum;
	marks[i].index=i;
	hDest=human;
	if(i!=4)
		proHumanDir(i,DIRS);
	if(marks[i].flag==OUTRANGE)
		return;
	latter(i,DIRS);
	if(marks[i].flag==DEAD)
		return;
	marks[i].robRe=d1;marks[i].minDist=minDist2;
	marks[i].flag=CANAVOID;
}

void process(int dir2)
{
	maps[human.x][human.y]=EMPTY;
	human.x+=dir[dir2][0];human.y+=dir[dir2][1];
	hDest=human;
	
	if(maps[hDest.x][hDest.y]==DEBRIS)
	{
		POINT nDest={hDest.x+dir[dir2][0],hDest.y+dir[dir2][1]};
		if(maps[nDest.x][nDest.y]==OCCUPIED)
		{
			for(int j=0;j<robNum;j++)
				if(nDest==Robots[j])
				{
					for(int k=j+1;k<robNum;k++)
						Robots[k-1]=Robots[k];
					robNum--;
					break;
				}
		}
		maps[nDest.x][nDest.y]=DEBRIS;
	}

	maps[hDest.x][hDest.y]=HUMAN;
	vector<indPot>indPV;indPV.clear();
	int flag[60];memset(flag,0,sizeof(int)*60);

	for(int j=0;j<robNum;j++)
	{
		int min=1000;int ind=-1;
		for(int k=0;k<9;k++)
		{
			POINT nPnt={Robots[j].x+dir[k][0],Robots[j].y+dir[k][1]};
			if(dist(nPnt,hDest)<min)
			{
				min=dist(nPnt,hDest);
				ind=k;
			}
		}
		POINT nPnt={Robots[j].x+dir[ind][0],Robots[j].y+dir[ind][1]};
		if(maps[nPnt.x][nPnt.y]==DEBRIS)
		{
			flag[j]=1;
			maps[Robots[j].x][Robots[j].y]=EMPTY;
		}
		else
			indPV.push_back(make_pair(j,nPnt));
	}

	vector<indPot>iV2;iV2.clear();
	for(int j=0;j<indPV.size();j++)
	{
		indPot pot=indPV.at(j);
		if(flag[pot.first]==1)
			continue;
		for(int k=j+1;k<indPV.size();k++)
		{
			indPot pot2=indPV.at(k);
			if(flag[pot2.first]==1)
				continue;
			if(pot2.second==pot.second)
			{
				flag[pot.first]=1;
				flag[pot2.first]=1;
				maps[pot.second.x][pot.second.y]=DEBRIS;
				maps[Robots[pot.first].x][Robots[pot.first].y]=EMPTY;
				maps[Robots[pot2.first].x][Robots[pot2.first].y]=EMPTY;
			}
		}
		if(flag[pot.first]==0)
			iV2.push_back(pot);
	}
	
	for(int j=0;j<iV2.size();j++)
	{
		indPot pot=iV2.at(j);
		maps[pot.second.x][pot.second.y]=10;
		if(maps[Robots[pot.first].x][Robots[pot.first].y]==10||maps[Robots[pot.first].x][Robots[pot.first].y]==DEBRIS)
			continue;
		maps[Robots[pot.first].x][Robots[pot.first].y]=EMPTY;
	}
	
	for(int j=0;j<iV2.size();j++)
	{
		indPot pot=iV2.at(j);
		if(maps[pot.second.x][pot.second.y]==10)
				maps[pot.second.x][pot.second.y]=OCCUPIED;
		Robots[pot.first].x=pot.second.x;Robots[pot.first].y=pot.second.y;
	}
	for(int j=0;j<robNum;j++)
	{
		if(flag[j]==1)
		{
			for(int k=j+1;k<robNum;k++)
			{
				Robots[k-1]=Robots[k];flag[k-1]=flag[k];
			}
			robNum--;j--;
		}
	}
}

int able(int sel)
{
	hDest=lists[sel];
	if(maps[hDest.x][hDest.y]==DEBRIS||maps[hDest.x][hDest.y]==OCCUPIED)
		return 0;
	memcpy(mapcy,maps,2500*sizeof(int));
	memcpy(rob2,Robots,sizeof(POINT)*51);
	rob2Num=robNum;
	return latter(sel,SELS);
}

void proSel(int sel)
{
	hDest=lists[sel];
	maps[human.x][human.y]=EMPTY;
	maps[hDest.x][hDest.y]=HUMAN;
	human=hDest;
	vector<indPot>indPV;indPV.clear();
	int flag[60];memset(flag,0,sizeof(int)*60);

	for(int j=0;j<robNum;j++)
	{
		int min=1000;int ind=-1;
		for(int k=0;k<9;k++)
		{
			POINT nPnt={Robots[j].x+dir[k][0],Robots[j].y+dir[k][1]};
			if(dist(nPnt,hDest)<min)
			{
				min=dist(nPnt,hDest);
				ind=k;
			}
		}
		POINT nPnt={Robots[j].x+dir[ind][0],Robots[j].y+dir[ind][1]};
		if(maps[nPnt.x][nPnt.y]==DEBRIS)
		{
			flag[j]=1;
			maps[Robots[j].x][Robots[j].y]=EMPTY;
		}
		else
			indPV.push_back(make_pair(j,nPnt));
	}

	vector<indPot>iV2;iV2.clear();
	for(int j=0;j<indPV.size();j++)
	{
		indPot pot=indPV.at(j);
		if(flag[pot.first]==1)
			continue;
		for(int k=j+1;k<indPV.size();k++)
		{
			indPot pot2=indPV.at(k);
			if(flag[pot2.first]==1)
				continue;
			if(pot2.second==pot.second)
			{
				flag[pot.first]=1;
				flag[pot2.first]=1;
				maps[pot.second.x][pot.second.y]=DEBRIS;
				maps[Robots[pot.first].x][Robots[pot.first].y]=EMPTY;
				maps[Robots[pot2.first].x][Robots[pot2.first].y]=EMPTY;
			}
		}
		if(flag[pot.first]==0)
			iV2.push_back(pot);
	}
	
	for(int j=0;j<iV2.size();j++)
	{
		indPot pot=iV2.at(j);
		maps[pot.second.x][pot.second.y]=10;
		if(maps[Robots[pot.first].x][Robots[pot.first].y]==10||maps[Robots[pot.first].x][Robots[pot.first].y]==DEBRIS)
			continue;
		maps[Robots[pot.first].x][Robots[pot.first].y]=EMPTY;
	}
	
	for(int j=0;j<iV2.size();j++)
	{
		indPot pot=iV2.at(j);
		if(maps[pot.second.x][pot.second.y]==10)
				maps[pot.second.x][pot.second.y]=OCCUPIED;
		Robots[pot.first].x=pot.second.x;Robots[pot.first].y=pot.second.y;
	}

	for(int j=0;j<robNum;j++)
	{
		if(flag[j]==1)
		{
			for(int k=j+1;k<robNum;k++)
			{
				Robots[k-1]=Robots[k];flag[k-1]=flag[k];
			}
			robNum--;j--;
		}
	}
}

void proStat()
{
	maps[human.x][human.y]=EMPTY;
	hDest=human;
	vector<indPot>indPV;indPV.clear();
	int flag[60];memset(flag,0,sizeof(int)*60);
	for(int j=0;j<robNum;j++)
	{
		int min=1000;int ind=-1;
		for(int k=0;k<9;k++)
		{
			POINT nPnt={Robots[j].x+dir[k][0],Robots[j].y+dir[k][1]};
			if(dist(nPnt,hDest)<min)
			{
				min=dist(nPnt,hDest);
				ind=k;
			}
		}
		POINT nPnt={Robots[j].x+dir[ind][0],Robots[j].y+dir[ind][1]};
		if(maps[nPnt.x][nPnt.y]==DEBRIS)
		{
			flag[j]=1;
			maps[Robots[j].x][Robots[j].y]=EMPTY;
		}
		else
			indPV.push_back(make_pair(j,nPnt));
	}

	vector<indPot>iV2;iV2.clear();
	for(int j=0;j<indPV.size();j++)
	{
		indPot pot=indPV.at(j);
		if(flag[pot.first]==1)
			continue;
		for(int k=j+1;k<indPV.size();k++)
		{
			indPot pot2=indPV.at(k);
			if(flag[pot2.first]==1)
				continue;
			if(pot2.second==pot.second)
			{
				flag[pot.first]=1;
				flag[pot2.first]=1;
				maps[pot.second.x][pot.second.y]=DEBRIS;
				maps[Robots[pot.first].x][Robots[pot.first].y]=EMPTY;
				maps[Robots[pot2.first].x][Robots[pot2.first].y]=EMPTY;
			}
		}
		if(flag[pot.first]==0)
			iV2.push_back(pot);
	}
	
	for(int j=0;j<iV2.size();j++)
	{
		indPot pot=iV2.at(j);
		maps[pot.second.x][pot.second.y]=10;
		if(maps[Robots[pot.first].x][Robots[pot.first].y]==10||maps[Robots[pot.first].x][Robots[pot.first].y]==DEBRIS)
			continue;
		maps[Robots[pot.first].x][Robots[pot.first].y]=EMPTY;
	}
	
	for(int j=0;j<iV2.size();j++)
	{
		indPot pot=iV2.at(j);
		if(maps[pot.second.x][pot.second.y]==10)
				maps[pot.second.x][pot.second.y]=OCCUPIED;
		Robots[pot.first].x=pot.second.x;Robots[pot.first].y=pot.second.y;
	}
	for(int j=0;j<robNum;j++)
	{
		if(flag[j]==1)
		{
			for(int k=j+1;k<robNum;k++)
			{
				Robots[k-1]=Robots[k];flag[k-1]=flag[k];
			}
			robNum--;j--;
		}
	}
}

int main()
{
	int cases=1;
	while(scanf("%d%d",&robNum,&listNum))
	{
		derNum=0;
		if(robNum==0&&listNum==0)
			break;
		memset(maps,0,sizeof(int)*2500);
		memset(listUsed,0,sizeof(int)*2500);
		for(int i=0;i<robNum;i++)
		{
			scanf("%d%d",&Robots[i].x,&Robots[i].y);
			maps[Robots[i].x][Robots[i].y]=OCCUPIED;
		}
		for(int i=0;i<listNum;i++)
			scanf("%d%d",&lists[i].x,&lists[i].y);
		human.x=human.y=15;
		maps[15][15]=HUMAN;listNNow=0;
		int step=0;
		printf("Case %d:\n",cases++);
		debNum=0;int flag5=0;
		while(robNum!=0)
		{
			step++;
			memset(marks,0,sizeof(MARK)*9);
			
			for(int i=0;i<9;i++)
				pro(i);
			
			qsort(marks,9,sizeof(MARK),cmp);
			int k;
			for(k=0;k<9;k++)
			{
				if(marks[k].flag==CANAVOID)
					break;
			}
			if(k<9)
				process(marks[k].index);
			else
			{
				int j;
				for(j=0;j<listNum;j++)
				{
					if(j==1)
						while(0);
					if(listUsed[j]==0&&able(j)==1)
					{
						proSel(j);
						printf("Move %d: teleport to (%d,%d)\n",step,lists[j].x,lists[j].y);
						listUsed[j]=1;
						break;
					}
				}
				if(j==listNum)
				{
					proStat();flag5=1;
					break;
				}
			}
			//printf("(%d,%d,%d)",robNum,human.x,human.y);
		}
		if(flag5==1)
			printf("Lost game after making %d moves.\n",step);
		else
			printf("Won game after making %d moves.\n",step);
		printf("Final position: (%d,%d)\n",human.x,human.y);
		debNum=0;
		for(int i=1;i<31;i++)
		{
			for(int j=1;j<=31;j++)
			{
				if(maps[i][j]==DEBRIS)
					debNum++;
			}
		}
		printf("Number of cells with debris: %d\n",debNum);
		if(flag5==1)
			printf("Number of robots remaining: %d\n",robNum);
		putchar('\n');
	}
	return 0;
}