#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int maxWins(int initialLevel,
            vector<int> const &grezPower) {
	vector<int> d=grezPower;
	sort(d.begin(),d.end());
	for(int i=0;i<d.size();i++)
	{
		if(initialLevel<=d.at(i)) return i;
		initialLevel+=d.at(i)/2;
	}
	return d.size();
}
