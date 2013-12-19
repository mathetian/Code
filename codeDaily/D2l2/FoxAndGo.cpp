#include <vector>
#include <string>
using namespace std;


typedef pair<int,int> ELEM;

int x[]={0,0,1,-1};int y[]={1,-1,0,0};

bool valide(int i,int j,int row,int col)
{
	if(i>=0&&j>=0&&i<row&&j<col)
		return 1;
	return 0;
}

void dfs(int i,int j,vector<string> const &board, vector<vector<int> > &flags,int&num,int&flag)
{
	int row=board.size(),col=board[0].size();
	if(valide(i,j,row,col)==1)
	{
		for(int k=0;k<4;k++)
		{
			int nx=i+x[k],ny=j+y[k];
			if(valide(nx,ny,row,col)==1)
			{
				if(board[nx][ny]=='.') flag=0;
				else if(board[nx][ny]=='o'&&flags[nx][ny]==0)
				{
					flags[nx][ny]=1;num++;
					dfs(nx,ny,board,flags,num,flag);
				}
			}
		}
	}
}

int fillHere(int a,int b,vector<string> &board)
{
	int row=board.size(),col=board[0].size();
	board[a][b]='x';int nums=0;
	vector<vector<int> >flags;
	flags=vector<vector<int> >(row,vector<int>(col,0));
	for(int i=0;i<row;i++)
    {
    	for(int j=0;j<col;j++)
    	{
    		if(board[i][j]=='o'&&flags[i][j]==0)
    		{		
    			int num=1;int flag=1;
    			flags[i][j]=1;
    			dfs(i,j,board,flags,num,flag);
    			if(flag==1) nums+=num;
    		}
    	}
    }
    board[a][b]='.';
    return nums;
}

int maxKill(vector<string> const &board) 
{
	vector<string>board1=board;
	int row=board.size(),col=board[0].size();
	int num=0;
	for(int i=0;i<row;i++)
    {
    	for(int j=0;j<col;j++)
    	{
    		if(board[i][j]=='.') 
    			num=max(fillHere(i,j,board1),num);
    	}
    }
    return num;
}
