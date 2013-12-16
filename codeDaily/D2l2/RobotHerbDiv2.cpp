#include <vector>
#include <string>
using namespace std;

int getdist(int T,vector<int> const &a) {
    int x=0,y=0;int flag=0;
    while(T--)
    for(int i=0;i<a.size();i++)
    {
        
    	if(flag==0) y+=a.at(i);
    	if(flag==1) x+=a.at(i);
    	if(flag==2) y-=a.at(i);
    	if(flag==3) x-=a.at(i);
    	flag=(flag+a[i])%4;
    }
    return abs(x)+abs(y);
}
