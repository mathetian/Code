#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

int maximumSpread(string const &chocolates, int maxSwaps) 
{
	int n=chocolates.size();int i;
	int mx=-1;
	FF(i,n)
	{
		vector<int> step;int left=0,right=0;
		for(int j=i-1;j>=0;j--)
		{
			if(chocolates.at(j)==chocolates.at(i)) step.push_back(left);
			else left++;
		}
		for(int j=i+1;j<n;j++)
		{
			if(chocolates.at(j)==chocolates.at(i)) step.push_back(right);
			else right++;
		}
		sort(step.begin(),step.end());
		int r=0;int s=0;
		for(int j=0;j<step.size();j++)
		{
			s+=step.at(j);
			if(s>maxSwaps) break;
			else r++;
		}
		mx=max(r,mx);
	}
    return mx+1;
}