#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

typedef pair<int,int> _tiiP;

void dfs(int i,vector<int>&_fV,vector<_tiiP>&_aV,int dist)
{
	_fV[i]=1;int a=_aV.at(i).first;int b=_aV.at(i).second;
	for(int j=0;j<_aV.size();j++)
	{
		if(_fV.at(j)==0)
		{
			int d=abs(_aV.at(j).first-a)+abs(_aV.at(j).second-b);
			if(d<=dist) dfs(j,_fV,_aV,dist);
		}
	}
}

int count(vector<string> const &field,
          int dist) {
	int row=field.size();int col=field.at(0).size();
	vector<_tiiP> _aV;int d=0;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(field[i][j]=='v') _aV.push_back(make_pair(i,j));
		}
	}
	vector<int> _fV(_aV.size(),0);
	for(int i=0;i<_aV.size();i++)
	{
		if(_fV.at(i)==0)
		{
			d++;
			dfs(i,_fV,_aV,dist);
		}
	}
	int r=1;
	for(int i=0;i<d;i++) r=(r*2)%1000000007;
	
	return (r-1)%1000000007;
}
