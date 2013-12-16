#include <vector>
#include <string>
using namespace std;

#define INF 0x3fffff

int maxDifference(vector<string> const &isFriend,
                  int d) {
    int m=isFriend.size();
    vector<vector<int> > _i2V(m,vector<int>(m,INF));
    for(int i=0;i<m;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		if(isFriend[i][j]=='Y') _i2V[i][j]=1;
    	}
    	_i2V[i][i]=1;
    }
    for(int k=0;k<m;k++)
    {
    	for(int i=0;i<m;i++)
	    {
	    	for(int j=0;j<m;j++) 
	    		_i2V[i][j]=min(_i2V[i][j],_i2V[i][k]+_i2V[k][j]);
	    }
    }
    int mx=0;
    for(int i=0;i<m;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		mx=max(mx,_i2V[i][j]);
    	}
    }
    if(mx==INF) return -1;
    return mx*d;
}
