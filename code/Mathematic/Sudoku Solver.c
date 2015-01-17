//["..9748...",
// "7........",
// ".2.1.9...",
// "..7...24.",
// ".64.1.59.",
// ".98...3..",
// "...8.3.2.",
// "........6",
// "...2759.."]

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        clearVector(flags);
        for(int i=0;i<board.size();i++)
        {
        	for(int j=0;j<board[0].size();j++)
        	{
        		if(board[i][j]=='.')
        			flags.push_back(make_pair(i,j));
        	}
        }

        m=board.size();
        n=flags.size();
        flag2=false;
        
        dfs(0,board);
        return;
    }
private:
	bool flag2;
	typedef pair<int,int>iP;
    vector<iP>flags;
	int m,n;

	void clearVector(vector<iP>&flags)
	{
		int len=flags.size();
		while(len--)
			flags.pop_back();
	}

	void dfs(int i,vector<vector<char> > &board)
	{
		if(flag2==true) return;
		if(i==n)
		{
			flag2=true;
			return;
		}
        vector<int>flag(10,0);
        int x=flags[i].first, y=flags[i].second;

        for(int j=0;j<m;j++)
        {
        	if(board[x][j]!='.')
        		flag[board[x][j]-1-'0']=1;
        	if(board[j][y]!='.')
        		flag[board[j][y]-1-'0']=1;
        }

        int x1=x/3;x1*=3;
        int y1=y/3;y1*=3;
        for(int j=0;j<3;j++)
        {
        	for(int k=0;k<3;k++)
        	{
        		if(board[x1+j][y1+k]!='.')
        			flag[board[x1+j][y1+k]-1-'0']=1;
        	}
        }
        for(int j=0;j<9;j++)
        {
        	if(flag[j]==0)
        	{
        		board[x][y]=j+1+'0';
        		dfs(i+1,board);
        		if(flag2==true)
        			return;
        		board[x][y]='.';
        	}
        }
	}

    bool visited_cells[20][20];
    bool visited_row[20][20];
    bool visited_col[20][20];
    
    void solveSudoku2(vector<vector<char>>& board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        memset(visited_cells, false, sizeof(visited_cells));  
        memset(visited_row, false, sizeof(visited_row));    
        memset(visited_col, false, sizeof(visited_col));  
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int cell = (i / 3) * 3 + j / 3;
                    int x = board[i][j] - '0';
                    visited_cells[cell][x] = true;
                    visited_row[i][x] = visited_col[j][x] = true;
                }
            }
        }
        
        isValidSudokuHelper(board, 0);
    }
    
    bool isValidSudokuHelper(vector<vector<char>>& board, int step) {
        if (step == 81) return true;
        
        int row = step / 9;
        int col = step % 9;
        int cell = (row / 3) * 3 + col / 3;
        
        if (board[row][col] != '.') {
            return isValidSudokuHelper(board, step + 1);
        }
        for (int i = 1; i <= 9; i++) {
            if (!visited_cells[cell][i] && !visited_row[row][i] && !visited_col[col][i]) {
                visited_cells[cell][i] = true;
                visited_row[row][i] = visited_col[col][i] = true;
                board[row][col] = '0' + i;
                bool flag = isValidSudokuHelper(board, step + 1);
                if (flag) return true;
                board[row][col] = '.';
                visited_cells[cell][i] = false;
                visited_row[row][i] = visited_col[col][i] = false;
            }
        }
        return false;
    }
};