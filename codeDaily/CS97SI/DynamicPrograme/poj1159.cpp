#include <iostream>
#include <string>
#include <string.h>
using namespace std;

#define SZ 5001

short int dp[SZ][SZ]; int n;
string str;

/*short int get(int x,int y)
{
	short int&res = dp[x][y];
	if(res != -1) return res;
	if(x == y) res = 0;
	else if(str.at(x) == str.at(y))
		res = get(x+1,y-1);
	else res = 1 + min(get(x + 1,y),get(x, y-1));
	return res; 
}
*/
int main()
{
	cin>>n>>str;int t,i,j;
	memset(dp,0,sizeof(dp));
	/*cout<<get(0,n-1)<<endl;*/
	for(t = 1;t < n;t++)
	{
		for(i = 0;i < n;i++)
		{
			j = i + t;
			if(j >= n) break;
			if(str.at(i) == str.at(j))
				dp[i][j] = dp[i + 1][j - 1];
			else
				dp[i][j] = 1 + min(dp[i+1][j],dp[i][j-1]);
		}
	}
	cout<<dp[0][n-1]<<endl;
	return 0;
}