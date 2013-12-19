#include <vector>
#include <string>
#include <math.h>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

double maximalLength(vector<int> const &height, int w) 
{
	int i,j,k;int n=height.size();
	vector<double>dp(101,0);
	for(i=1;i<n;i++)
	{
		vector<double>dp2(height.at(i),0);
		for(j=1;j<=height.at(i);j++)
		{
			double val=0;
			for(k=1;k<=height.at(i-1);k++)
			{
				double tmp=dp[k-1]+sqrt(w*w+(j-k)*(j-k));
				val=max(tmp,val);
			}
			dp2[j-1]=val;
		}
		dp=dp2;
	}
	double m=dp.at(0);
	for(i=1;i<=height.at(n-1);i++)
	{
		m=max(m,dp.at(i-1));
	}
    return m;	
}
