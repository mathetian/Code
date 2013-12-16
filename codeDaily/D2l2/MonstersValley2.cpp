#include <vector>
#include <string>
using namespace std;
#define MX 2000000000

int m=0;
void dfs(int index,int n,int cost,int value, vector<int> const &dread, vector<int> const &price)
{
	if(index==n) m=min(m,cost);
	else
	{
		//with
		int remain=MX-value;
		if(remain<=dread.at(index)) dfs(index+1,n,cost+price.at(index),MX,dread,price);
		else dfs(index+1,n,cost+price.at(index),value+dread.at(index),dread,price);
		//not
		if(value>=dread.at(index)) dfs(index+1,n,cost,value,dread,price);
	}
}
int minimumPrice(vector<int> const &dread,
                 vector<int> const &price) {
   	m=MX;
   	dfs(0,dread.size(),0,0,dread,price);
    return m;
}