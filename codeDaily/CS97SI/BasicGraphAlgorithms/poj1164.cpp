#include <iostream>
#include <algorithm>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};


char matrix[51][51];int dat[51][51];
int m,n; 

int dfs(int x,int y)
{
	int rs=1;
	int i;FF(i,4)
	{
		int nx=x+dx[i];int ny=y+dy[i];
		if(nx<0||ny<0||nx>=m||ny>=n) continue;
		if(matrix[nx][ny]==1) continue;
		int flag=0;
		switch(i)
		{
		case 0:
			if((dat[x][y] & 4) != 0) flag=1;
		break;
		case 1:
			if((dat[x][y] & 1) != 0) flag=1;
		break;
		case 2:
			if((dat[x][y] & 8) != 0) flag=1;
		break;
		case 3:
			if((dat[x][y] & 2) != 0) flag=1;
		break;
		}
		if(flag == 1) continue;
		matrix[nx][ny]=1;rs+=dfs(nx,ny);
	}
	return rs;
}

int main()
{
	cin>>m>>n; int i,j;FF(i,m)FF(j,n)
	cin>>dat[i][j];
	memset(matrix,0,sizeof(matrix));
	int roomNum = 0,biggestNum = 0;
	FF(i,m)FF(j,n)
	{
		if(matrix[i][j]==0)
		{
			matrix[i][j]=1;
			roomNum++;
			biggestNum=max(dfs(i,j),biggestNum);
		}
	}
	cout<<roomNum<<endl;
	cout<<biggestNum<<endl;
}