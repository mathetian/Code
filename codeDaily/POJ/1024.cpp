
#include<iostream>
#include<queue>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

int width,height;

typedef struct{
	int up,down,left,right;
	int nearOrg;int nearDest;int flag;
}POINT;

POINT maps[100][100];

int staP[2];int endP[2];int wallNum;

typedef pair<int,int> IIP;
typedef pair<IIP,IIP>iipp;

vector<iipp>IPV;

int dirX[]={-1,1,0,0};
int dirY[]={0,0,-1,1};

int able(int px,int py,int dir,int flag)
{
	int tX=px+dirX[dir];int tY=py+dirY[dir];
	if(dir==0)
	{
		if(maps[px][py].up==1)
			return 0;
	}
	else if(dir==1)
	{
		if(maps[px][py].down==1)
			return 0;
	}
	else if(dir==2)
	{
		if(maps[px][py].left==1)
			return 0;
	}
	else if(dir==3)
	{
		if(maps[px][py].right==1)
			return 0;
	}
	if(tX>=0&&tX<height)
	{
		if(tY>=0&&tY<width)
		{
			if(flag==0)
			{
				if(tX==0&&tY==0)
					return 0;
			}
			else
			{
				if(tX==endP[0]&&tY==endP[1])
					return 0;
			}
			if(flag==0)
			{
				if(maps[tX][tY].nearOrg==0)
					return 1;
				else
					return 0;
			}
			else
			{
				if(maps[tX][tY].nearDest==0)
					return 1;
				else
					return 0;
			}
		}
	}
	return 0;
}

void bfs(int index,queue<IIP>&iiQ)
{
	while(!iiQ.empty())
	{
		int px=iiQ.front().first;int py=iiQ.front().second;
		iiQ.pop();
		for(int i=0;i<4;i++)
		{
			if(px==3&&py==7)
			{
				while(0);
			}
			if(able(px,py,i,index)==1)
			{
				if(index==0)
					maps[px+dirX[i]][py+dirY[i]].nearOrg=maps[px][py].nearOrg+1;
				else
					maps[px+dirX[i]][py+dirY[i]].nearDest=maps[px][py].nearDest+1;
				iiQ.push(make_pair(px+dirX[i],py+dirY[i]));
			}
		}
	}
}

void dealWall(int wallNum)
{
	for(int i=0;i<wallNum;i++)
		{
			int p1x,p1y;int p2x,p2y;
		//	scanf("%d%d%d%d",&p1y,&p1x,&p2y,&p2x);
			cin>>p1y>>p1x>>p2y>>p2x;
			IPV.push_back(make_pair(make_pair(p1x,p1y),make_pair(p2x,p2y)));
			if(p1x==p2x)
			{
				if(p1y<p2y)
				{   
					maps[p1x][p1y].right=1;maps[p2x][p2y].left=1; 
				}
				else
				{
					maps[p1x][p1y].left=1;maps[p2x][p2y].right=1;
				}
			}
			else
			{
				if(p1x<p2x)
				{
					maps[p1x][p1y].down=1;maps[p2x][p2y].up=1;
				}
				else
				{
					maps[p1x][p1y].up=1;maps[p2x][p2y].down=1;
				}
			}
		}
}

int main()
{
	int cases;
//	scanf("%d",&cases);
	cin>>cases;
	while(cases--)
	{
		queue<IIP>iiQ;
		string input;
		cin>>width>>height;
		memset(maps,0,sizeof(POINT)*100*100);
		cin>>input;
		int len=input.size();
		int u=0,r=0;maps[0][0].flag=1;
		for(int i=0;i<len;i++)
		{
			switch(input[i])
			{
				case 'U': u++;break;
				case 'D':u--;break;
				case 'R':r++;break;
				case 'L':r--;break;
			}
			maps[u][r].flag=1;
		}
		staP[0]=0;staP[1]=0;
		endP[0]=u;endP[1]=r;
		
		IPV.clear();
		//scanf("%d",&wallNum);
		cin>>wallNum;
		dealWall(wallNum);
		
		iiQ.push(make_pair(0,0));
		bfs(0,iiQ);
		iiQ.push(make_pair(endP[0],endP[1]));
		bfs(1,iiQ);

		for(int i=0;i<height;i++)
		{
			for(int j=0;j<width;j++)
			{
				if((maps[i][j].nearOrg==0)&&(maps[i][j].nearDest==0))
				{
				//	printf("%d %d 1INCORRECT\n",i,j);
					cout<<"INCORRECT\n";
					goto label1;
				}
				else if(maps[i][j].nearOrg+maps[i][j].nearDest<len)
				{
					//printf("%d %d2INCORRECT\n",i,j);
					cout<<"INCORRECT\n";
					goto label1;
				}
				else if(maps[i][j].nearOrg+maps[i][j].nearDest==len)
				{
					if(maps[i][j].flag==0)
					{
						//printf("3INCORRECT\n");
						cout<<"INCORRECT\n";
						goto label1;
					}
				}
			}
		}
		
		for(int i=0;i<wallNum;i++)
		{
			int p1x,p1y;int p2x,p2y;
			p1x=IPV[i].first.first;p1y=IPV[i].first.second;
			p2x=IPV[i].second.first;p2y=IPV[i].second.second;
			if((maps[p1x][p1y].nearOrg+1+maps[p2x][p2y].nearDest<=len)||maps[p1x][p1y].nearDest+1+maps[p2x][p2y].nearOrg<=len)
			{
			}
			else
			{
				//printf("INCORRECT\n");
				cout<<"INCORRECT\n";
				goto label1;
			}
		}
		//printf("CORRECT\n");
		cout<<"CORRECT\n";
	label1:;
	}
	return 0;
}