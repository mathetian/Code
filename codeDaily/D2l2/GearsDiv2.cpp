#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//dp[i][0]=min(dp[i-1][0],dp[i-1][1])+1
//dp[i][1]=(a[i-1]==a[i])?dp[i-1][0]:min(dp[i-1][0],dp[i-1][1])

/*int dp(string const &Directions)
{
	int n=Directions.size();
	vector<vector<int> >f(n,vector<int>(2,0));
	f[0][0]=1;f[0][1]=0;
	for(int i=1;i<n;i++)
	{	
		f[i][0]=min(f[i-1][0],f[i-1][1])+1;
		f[i][1]=(Directions.at(i-1)==Directions.at(i))?f[i-1][0]:min(f[i-1][0],f[i-1][1]);
	}
	return min(f[n-1][0],f[n-1][1]);
}

int getmin(string const &Directions) {
	int n=Directions.size();
	if(Directions.at(0)==Directions.at(n-1)) 
		return min(dp(Directions.substr(0,n-1)),dp(Directions.substr(1,n-1)))+1;
	else return dp(Directions);
}*/

//Python solution
int getmin(string const &Directions) 
{
	int n=Directions.size();
	int i=1;
	while(i<n&&Directions.at(i)==Directions.at(0)) i++;
	if(i==n) return n/2+n%2;

	char prev=Directions.at(0);int offset=i;i=0;
	int cnt=0;
	while(i<n)
	{
		int c=(offset+i)%n;
		if(prev=='E') prev=Directions.at(c);
		else if(prev!=Directions.at(c))
			prev=Directions.at(c);
		else
			cnt++,prev='E';
		i++;
	}
	return cnt;
}	
