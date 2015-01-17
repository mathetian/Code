class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       this->flag=vector<vector<int> >(n,vector<int>(n,0));
       this->n=n;this->num=0;vector<int>rs;
       clearVector(rs2);
       dfs(rs,0);
       return rs2;
    }
private:
	int num;int n;
	vector<vector<int> >flag;
	vector<vector<string> >rs2;

	void clearVector(vector<vector<string> >&rs2)
	{
		int len=rs2.size();
		while(len--)
			rs2.pop_back();
	}

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
	
	void dfs(vector<int>&rs,int line)
	{
		if(n==line)
		{
			num++;
			vector<string>rs3;
			for(int i=0;i<n;i++)
			{
				string s(n,'.');
				s[rs[i]]='Q';
				rs3.push_back(s);
			}
			rs2.push_back(rs3);
			return;
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				if(valid(line,i)==1)
				{
					rs.push_back(i);
					flag[line][i]=1;
					dfs(rs,line+1);
					rs.pop_back();
					flag[line][i]=0;
				}
			}
		}
	}
};