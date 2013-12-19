#include <vector>
#include <string>
#include <string.h>
using namespace std;

vector<int> revenues;double dp[51];

/**Boundary situation**/
/**
	dp[a]=(dp[b]+...)/(a-b+1)
**/

double findMaximum(vector<int> const &rr, int k) 
{
	vector<int> revenues(rr.begin(),rr.end());
	sort(revenues.begin(),revenues.end());
	int i,j,l;double sum;memset(dp,0,sizeof(dp));
	for(i=k-1;i<rr.size();i++)
	{
		sum=0;for(j=0;j<=i;j++) sum+=revenues.at(j);
		dp[i]=sum/(i+1);double&res=dp[i];
		for(j=i-1;j>=k-1;j--)
		{
			if(i-j+1<k) continue;
			sum=dp[j];for(l=j+1;l<=i;l++) sum+=revenues.at(l);
			res=max(res,sum/(i-j+1));
		}
	}	
    return dp[rr.size()-1];
}
