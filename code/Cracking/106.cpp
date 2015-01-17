#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

#include <string.h>

struct Line_t
{
	int y, intercept;
};

typedef struct Line_t Line;

struct Point_t
{
	int x,y;
};

typedef struct Point_t Point;

Line getLine(Point&p1,Point&p2)
{

}

int getMost(vector<Point>&points)
{
	map<Line,int> lines;int mx=1;
	for(int i=0;i<points.size();i++)
	{
		for(int j=i+1;j<points.size();j++)
		{
			Line line = getLine(points.at(i),points.at(j));
			if(lines.find(line) == lines.end())
				lines[line]=0;
			lines[line]++;
			mx=max(mx,lines[line]);
		}
	}
	return mx;
}

int main()
{
	return 0;
}