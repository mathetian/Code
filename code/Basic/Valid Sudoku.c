class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m=board.size();
        for(int i=0;i<m;i++)
        {
        	for(int j=0;j<m;j++)
        	{
        		if(board[i][j]!='.')
        		{
        			char v=board[i][j];
        			for(int k=0;k<m;k++)
        			{
        				if(k!=j&&board[i][k]==v)
        					return false;
        				if(k!=i&&board[k][j]==v)
        					return false;
        			}
        			int x=i/3;x*=3;
        			int y=j/3;y*=3;
        			for(int k=0;k<3;k++)
        			{
        				for(int l=0;l<3;l++)
        				{
        					if(x+k!=i&&y+l!=j)
        					{
        						if(board[x+k][y+l]==v)
        							return false;
        					}
        				}
        			}
        		}
        	}
        }
        return true;
    }
};