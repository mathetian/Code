#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> countSolutions(vector<int> const &Y,
                           vector<int> const &query) {
    
	vector<int> rs;int a,b,c,d,e;
	for(int i=0;i<query.size();i++)
	{
		e=query.at(i);int r=0;
		for(int j=0;j<Y.size()-1;j++)
		{
			a=Y.at(j);b=Y.at(j+1);
			c=max(a,b);d=min(a,b);
			if(a==b)
			{
				if(e==a)
				{
					r=-1;break;
				}
			}
			else if(e<c&&e>d) r++;
			else if(e==a) r++;
		}
		if(r!=-1&&e==Y.at(Y.size()-1)) r++;
		rs.push_back(r);
	}
    return rs;
}
