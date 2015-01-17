#include <iostream>
using namespace std;

typedef struct _tNode{
	int parent,cNums;
	_tNode(int id){parent=-1;cNums=0;}
}Node;

vector<Node> nodes(30005,0);

int find(int id)
{
	if(nodes[i].parent!=-1)
		nodes[id].parent=id;
}

int union1(int x,int y)
{
	int xp=find(x), yp=find(y);

}

int main()
{
	int P;cin>>P;
	char flag;int x,y;
	while(P--)
	{
		cin>>flag;
		if(flag=='M') cin>>x>>y;
		else cin>>x;
		if(flag=='M')
			union1(x,y);
	}
	return 0;
}