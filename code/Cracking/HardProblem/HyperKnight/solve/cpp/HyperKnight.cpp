#include <vector>
#include <string>
using namespace std;

int r,c;
// (+a,+b), (+a,-b), (-a,+b), (-a,-b), (+b,+a), (+b,-a), (-b,+a), and (-b,-a)
int a,b;

int valid(int x,int y)
{
	if(x<0||y<0||x>=r||y>=c) return 0;
	return 1;
}

int x1[]={1,1,-1,-1};
int y1[]={1,-1,1,-1};

int getNum(int x,int y)
{
	int t=0;
	for(int i=0;i<4;i++) t+=valid(x+x1[i]*a,y+y1[i]*b);
	for(int i=0;i<4;i++) t+=valid(x+x1[i]*b,y+y1[i]*a);
	return t;
}

int64 countCells(int a1,int b1,int numRows,int numColumns,int k) {
    int mx=numRows/2,my=numColumns/2;
    while(mx<numRows&&my<numColumns)
    {
    	
    }
    return 0;
}
