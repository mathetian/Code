#include <vector>
#include <string>
using namespace std;

vector<int> find(vector<int> const &heights) {
	int n=heights.size();vector<int> h;
	for(int i=0;i<n;i++) h.push_back(i);
	int mx=0x3fffff;
	vector<int> rs;
	do{
		int tmp=0;
		for(int i=0;i<h.size()-1;i++) tmp+=max(heights.at(h.at(i)),heights.at(h.at(i+1)));
		if(tmp<mx) rs=h;
		mx=min(mx,tmp);
	}while(next_permutation(h.begin(),h.end()));
    return rs;
}
