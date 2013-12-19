#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

double expectedHeads(int N, vector<int> const &a) 
{
	vector<double> p(N,1.0);int i,j;
	FF(i,a.size())
	{
		double p1=a.at(i)/(double)N;
		FF(j,N) p[j]=p[j]*(1-p1)+(1-p[j])*p1;
	}
	double rs=0;//accumulate(p.begin(),p.end(),rs);
    FF(i,N) rs+=p.at(i);return rs;
}
