#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       flag=vector<vector<int> >(n,vector<int>(n,0));
       this->n=n;num=0;
       dfs(0);
       return num;
    }
private:
	int num;int n;
	vector<vector<int> >flag;
	bool valid(int line,int i)
	{
		for(int j=0;j<line;j++)
			if(flag[j][i]==1)
				return false;

		int x=line-1;int y=i-1;
		while(x>=0&&y>=0)
		{
			if(flag[x][y]==1)
				return false;
			x--;y--;
		}
		x=line-1;y=i+1;
		while(x>=0&&y<n)
		{
			if(flag[x][y]==1)
				return false;
			x--;y++;
		}
		return true;
	}
	
	void dfs(int line)
	{
		if(n==line)
			num++;
		else
		{
			for(int i=0;i<n;i++)
			{
				if(valid(line,i)==1)
				{
					flag[line][i]=1;
					dfs(line+1);
					flag[line][i]=0;
				}
			}
		}
	}
};

int main()
{
	Solution solution;
	std::cout<<solution.totalNQueens(12)<<endl;
}