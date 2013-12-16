#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

int shortestLadder(vector<string> const &level,
                   int coinRow,
                   int coinColumn) {
   
  	int a=level.size(),b=level.at(0).size();
    for(int i=0;i<=50;i++)
    {
    	 queue<pair<int,int> >iiPQ;
    	 iiPQ.push(make_pair(a-1,0));

    	 vector<vector<char> >flags(a,vector<char>(b,0));
    	 flags[a-1][0]=1;
    	 while(!iiPQ.empty())
    	 {
    	 	int row=iiPQ.front().first;
    	 	int col=iiPQ.front().second;
    	 	iiPQ.pop();
    	 	if(row==coinRow-1&&col==coinColumn-1) return i;
    	 	int j=col-1;
    	 	while(j>=0&&level[row][j]=='X')
    	 	{
    	 		if(flags[row][j]==0)
    	 		{
    	 			iiPQ.push(make_pair(row,j));
    	 			flags[row][j]=1;
    	 		}
    	 		j--;
    	 	}
    	 	j=col+1;
    	 	while(j<b&&level[row][j]=='X')
    	 	{
    	 		if(flags[row][j]==0)
    	 		{
    	 			iiPQ.push(make_pair(row,j));
    	 			flags[row][j]=1;
    	 		}
    	 		j++;
    	 	}
    	 	for(j=1;j<=i;j++)
    	 	{
    	 		if(row+j<a&&flags[row+j][col]==0&&level[row+j][col]=='X')
    	 		{
    	 			iiPQ.push(make_pair(row+j,col));
    	 			flags[row+j][col]=1;
    	 		}
    	 		if(row-j>=0&&flags[row-j][col]==0&&level[row-j][col]=='X')
    	 		{
    	 			iiPQ.push(make_pair(row-j,col));
    	 			flags[row-j][col]=1;
    	 		}
    	 	}
    	 }
    }
    return -1;
}

/*int main()
{
	vector<string> level;
	level.push_back("XXXX....");
	level.push_back("...X.XXX");
	level.push_back("XXX..X..");
	level.push_back("......X.");
	level.push_back("XXXXXXXX");
	cout<<shortestLadder(level,2,4)<<endl;
}*/