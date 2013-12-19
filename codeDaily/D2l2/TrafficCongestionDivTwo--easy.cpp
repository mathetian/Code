#include <vector>
#include <string>
using namespace std;

int64 theMinCars(int treeHeight) {
	if(treeHeight<=1) return 1;
    vector<int64>f(treeHeight+1,0);
    f[0]=1;f[1]=1;
    for(int i=2;i<=treeHeight;i++)
    {
    	for(int j=0;j<=i-2;j++)
    		f[i]+=2*f[j];
    	f[i]+=1;
    }
    return f[treeHeight];
}
