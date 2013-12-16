#include <vector>
#include <string>
using namespace std;

int count(vector<int> const &s,
          vector<int> const &t) {
    int n=0;
    for(int i=0;i<s.size();i++)
    {
    	for(int j=i+1;j<s.size();j++)
    	{
    		if(t.at(i)<t.at(j))
    		{
    			if(s.at(j)<=t.at(i)) n++;
    		}
    		else if(t.at(i)>t.at(j))
    		{
    			if(s.at(i)<=t.at(j)) n++;
    		}
    		else n++;
    	}
    }
    return n;
}
