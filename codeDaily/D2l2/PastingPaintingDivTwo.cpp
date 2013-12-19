#include <vector>
#include <string>
#include <set>
using namespace std;

int64 countColors(vector<string> const &clipboard,
                  int T) {
    int64 num=0;int64 diff=0;
    int r=clipboard.size(),c=clipboard.at(0).size();
    set<pair<int,int> >_iiSet;
    for(int k=0;k<min(r,T);k++)
    {
    	diff=0;
    	for(int i=0;i<r;i++)
    	{
    		for(int j=0;j<c;j++)
    		{
    			if(clipboard[i][j]=='B')
    			{
    				pair<int,int> a=make_pair(i+k,j+k);
    				if(_iiSet.find(a)==_iiSet.end())
    				{	
    					_iiSet.insert(a);
    					num++;diff++;
    				}
    			}
    		}
    	}
    }
    if(T<=r) return num;
    return num+(T-r)*diff;
}
