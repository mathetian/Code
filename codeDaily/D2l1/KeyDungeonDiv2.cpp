#include <vector>
#include <string>
using namespace std;

int countDoors(vector<int> const &doorR,
               vector<int> const &doorG,
               vector<int> const &keys) {
    int l=doorR.size();int a=keys[0],b=keys[1],c=keys[2];
    int r=0;
    for(int i=0;i<l;i++)
    {
    	int d=doorR.at(i),e=doorG.at(i);
    	d-=a;e-=b;
    	if(d<0) d=0;if(e<0) e=0;
    	if(d+e<=c) r++;
    }
    return r;
}
