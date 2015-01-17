#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        flag=false;
        this->board=board;
        int sa=board.size();
        if(sa==0)
        	return 0;
        int sb=board[0].size();
        if(sb==0)
        	return 0;
        xd=new int[4];yd=new int[4];
        xd[0]=0;xd[1]=0;
        xd[2]=1;xd[3]=-1;

        yd[0]=1;yd[1]=-1;
        yd[2]=0;yd[3]=0;

        flags=vector<vector<char> >(sa,vector<char>(sb,0));

       	for(int i=0;i<sa;i++)
       	{
       		for(int j=0;j<sb;j++)
       		{
       			if(board[i][j]==word[0])
       			{
       				flags[i][j]=1;
       				dfs(word,1,i,j);
       				flags[i][j]=0;
       				if(flag==true)
       					return true;
       			}
       		}
       	}
       	return false;
    }
private:
	bool flag;
	vector<vector<char> >board;
	vector<vector<char> >flags;
	int*xd;int*yd;
	void dfs(string word,int pos,int x,int y)
	{
		if(flag==true)
			return;
		if(pos==word.size())
		{
			flag=true;
			return;
		}
		for(int i=0;i<4;i++)
		{
			int nx=x+xd[i];
			int ny=y+yd[i];
			if(nx>=0&&nx<board.size()&&ny>=0&&ny<board[0].size())
			{
				if(board[nx][ny]==word[pos]&&flags[nx][ny]==0)
				{
					flags[nx][ny]=1;
					dfs(word,pos+1,nx,ny);
					flags[nx][ny]=0;
					if(flag==true)
						return;
				}
			}
		}
	}
};

int main()
{
	vector<vector<char> > bb;
	vector<char>ts;
	ts.push_back('a');ts.push_back('b');
	bb.push_back(ts);
	vector<char>ts1;
	ts1.push_back('c');ts1.push_back('d');
	bb.push_back(ts1);
	Solution solution;
	std::cout<<solution.exist(bb,"cdba")<<endl;
	return 0;
}