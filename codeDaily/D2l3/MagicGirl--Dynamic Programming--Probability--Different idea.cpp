#include <vector>
#include <string>
#include <string.h>
using namespace std;

/**
	dp[witch][curLP]
	not attack witch+1, b=curLP-day[witch+1]+day[witch]
	attack, a=dp[witch+1][(b+gain[witch+1])]*win[witch+1]+day[witch+1]*(1-win[witch+1])
	c=max(a,b)
	dp[witch][curLP]=max(dp[witch+1][b],dp[witch+1][a])
	boundary:
	1. witch, 1 2 3 4 ..
	2. last witch -> day[last witch]+curLP

	Not very directly dynamic programming.
	Probability problem.

	Not very understood.
**/

/**
	a=lp-day[witch+1]+day[witch]
	if not dp[witch][lp]=dp[witch+1][a]
	if, lose day[witch+1]
		win dp[witch+1][a+gain[witch+1]]
		so, lose*(1-win[witch+1])+win*win[witch+1]
	Therefore,
	dp[witch][lp]=max(dp[witch+1][a],day[witch+1]*(1-win[witch+1])+dp[witch+1][a+gain[witch+1]]*win[witch+1])
**/
#define FF(i,n) for(i=0;i<n;i++)

vector<int> day;vector<int> win;vector<int> gain;int n;
double dp[51][100001];int M;
int flags[51][100001];
void tripleSort()
{
	int i,j;FF(i,n)
	{
		int a=day.at(i),b=win.at(i),c=gain.at(i);
		for(j=i-1;j>=0;j--)
		{
			if(day.at(j)>a)
			{
				day[j+1]=day[j];
				win[j+1]=win[j];
				gain[j+1]=gain[j];
			}
			else break;
		}
		day[j+1]=a;win[j+1]=b;gain[j+1]=c;
	}
}

double get(int witch,int lp)
{
	double&res=dp[witch][lp];
	int&flag=flags[witch][lp];if(flag!=0) return res;
	if(witch==day.size()) res=lp+day[witch-1];
	else if(witch!=0)
	{
		int a=lp-day[witch]+day[witch-1];
		if(a<=0) res=day[witch-1]+lp;
		else res=max(get(witch+1,a),day[witch]*(1-win[witch]/100.0)+get(witch+1,min(M,a+gain[witch]))*win[witch]/100.0);
	}
	else
	{
		int a=lp-day[witch];if(a<=0) res=lp;
		else res=max(get(witch+1,a),day[witch]*(1-win[witch]/100.0)+get(witch+1,min(M,a+gain[witch]))*win[witch]/100.0);
	}
	flag=1;
	//cout<<"witch: "<<witch<<" lp:"<<lp<<" res:"<<res<<endl;
	return res;
}

double maxExpectation(int M1, vector<int> const &day1, vector<int> const &win1, vector<int> const &gain1) 
{
	day=vector<int>(day1.begin(),day1.end());
	win=vector<int>(win1.begin(),win1.end());M=M1;
	gain=vector<int>(gain1.begin(),gain1.end());
	memset(flags,0,sizeof(flags));n=day.size();tripleSort();
	return get(0,M);
}
