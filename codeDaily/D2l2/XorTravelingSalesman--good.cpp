#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

typedef pair<int,int> iiP;
int maxProfit(vector<int> const &cityValues, vector<string> const &roads) 
{
	char dp[50][1024];memset(dp,0,50*1024);
	int n=cityValues.size();
	dp[0][cityValues.at(0)]=1;int r=-1;
	queue<iiP>iQ;iQ.push(make_pair(0,cityValues.at(0)));
	while(!iQ.empty())
	{
		int id=iQ.front().first;
		int val=iQ.front().second;
		iQ.pop();r=max(r,val);
		for(int i=0;i<n;i++)
		{
			if((roads.at(id)).at(i)=='N') continue;
			int r1=val^(cityValues.at(i));
			if(dp[i][r1]==0)
			{
				dp[i][r1]=1;
				iQ.push(make_pair(i,r1));
			}
		}
	}
    return r;
}

/*int main()
{
	int a1[]={878, 85, 760, 579};
	string a2[]={"NYNN", "YNYY", "NYNY", "NYYN"};
	vector<int> cityValues(a1,a1+4);vector<string> roads(a2,a2+4);
	cout<<maxProfit(cityValues,roads)<<endl;
	return 0;
}
*/