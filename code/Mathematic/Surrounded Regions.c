#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void print(vector<vector<char> >rs)
{
    std::cout<<endl;
    for(int i=0;i<rs.size();i++)
    {
        for(int j=0;j<rs[0].size();j++)
        {
           std::cout<<rs[i][j];
        }
           
        std::cout<<endl;
    }
}

class Solution {
public:
    void solve(vector<vector<char> > &board) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(board.empty())
            return;
        a=board.size();b=board[0].size();
       // cout<<a<<" "<<b<<endl;
        int i,j;
        for(i=0;i<b;i++)
        {
        	if(board[0][i]=='O')
        		bfs(board,0,i);
        	if(board[a-1][i]=='O')
        		bfs(board,a-1,i);
        }
         for(i=0;i<a;i++)
        {
        	if(board[i][0]=='O')
        		bfs(board,i,0);
        	if(board[i][b-1]=='O')
        		bfs(board,i,b-1);
        }
        for(i=0;i<a;i++)
        	for(j=0;j<b;j++)
                if(board[i][j]=='O')
                    board[i][j]='X';
        		else if(board[i][j]=='+')
        			board[i][j]='O';
    }
private:
	int a,b;
	typedef pair<int,int>iPair;
	queue<iPair>iPQ;
	void bfs(vector<vector<char> >&board,int i,int j)
	{
       static int flags[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
	   while(!iPQ.empty())
            iPQ.pop();	
	   iPQ.push(make_pair(i,j));
       board[i][j]='+';
	   while(!iPQ.empty())
	   {
	       	iPair tmp=iPQ.front();iPQ.pop();
			for(i=0;i<4;i++)
			{
				int newX=tmp.first+flags[i][0];
				int newY=tmp.second+flags[i][1];
				if(newX<0||newX>=a||newY<0||newY>=b||board[newX][newY]!='O')
					continue;
				board[newX][newY]='+';
				iPQ.push(make_pair(newX,newY));
			}
		}
	}
};
/*
X X X X
X O O X
X X O X
X O X X
*/
void clearVector(vector<char>&v)
{
    std::vector<char>::iterator it=v.begin();
    std::vector<char>::iterator et=v.end();
    v.erase(it,et);
}

void insertV(vector<char>&v,string str)
{
    for(int i=0;i<str.length();i++)
        v.push_back(str[i]);
}



int main()
{
    vector<vector<char> > rs;
   /* vector<char>tmp;
    string strs[4]={"XXXX","XOOX","XXOX","XOXX"};
    for(int i=0;i<4;i++)
    {
        clearVector(tmp);
        insertV(tmp,strs[i]);
        rs.push_back(tmp);
    }*/
    Solution solution;
    solution.solve(rs);
    //print(rs);
}