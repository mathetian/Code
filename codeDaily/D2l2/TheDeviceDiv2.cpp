#include <vector>
#include <string>
using namespace std;

string identify(vector<string> const &plates) {
    if(plates.size()<3) return "NO";
    for(int i=0;i<plates.at(0).size();i++)
    {
    	int one=0;
    	for(int j=0;j<plates.size();j++)
    	{	
    		if(plates[j][i]=='1') one++;
    	}
    	if(one==plates.size()||one<2) return "NO";
    }
    return "YES";
}
