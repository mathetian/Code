#include <vector>
#include <string>
#include <iostream>
using namespace std;

string win(vector<string> const &board) {
    int a=board.size(),b=board[0].size();
    for(int i=0;i<a;i++)
    {
    	for(int j=0;j<b;j++)
    	{
    		if(board[i][j]=='o')
    		{
    			//row
    			if(j-1>=0&&board[i][j-1]=='o'){}
    			else if(j+5<=b)
    			{
    				int k;
    				for(k=1;k<5;k++)
	    			{
	    				if(board[i][j+k]!='o')
	    					break;
	    			}
	    			if(k==5) return "found";
    			}
    			//column
    			if(i-1>=0&&board[i-1][j]=='o'){}
    			else if(i+5<=a)
    			{
    				int k;
    				for(k=1;k<5;k++)
	    			{
	    				if(board[i+k][j]!='o')
	    					break;
	    			}
	    			if(k==5) return "found";
    			}
    			//degree
    		    //right
    			if(i-1>=0&&j-1>=0&&board[i-1][j-1]=='o'){}
                else
    			{
                    if(i+5<=a&&j+5<=b)
                    {
                        int k;
                        for(k=1;k<5;k++)
                        {
                            if(board[i+k][j+k]!='o')
                                break;
                        }
                        if(k==5) return "found";
                    }
    			}
    		    //left
                if(i-1>=0&&j+1<b&&board[i-1][j+1]=='o'){}
                else
                {
                    if(i+5<=a&&j-5>=-1)
                    {
                        int k;
                        for(k=1;k<5;k++)
                        {
                            if(board[i+k][j-k]!='o')
                                break;
                        }
                        if(k==5) return "found";
                    }
                }
    		}
    	}
    }
    return "not found";
}

/*int main()
{
    vector<string>board;
    board.push_back("....o.");
    board.push_back("...o..");
    board.push_back("..o...");
    board.push_back(".o....");
    board.push_back("o.....");
    board.push_back("......");
    cout<<win(board)<<endl;
    return 0;
}*/