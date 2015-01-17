#include <iostream>
#include <string>
using namespace std;
#include <string.h>
#define FF(i, n) for(i = 0;i < n;i++)
#define FS(i, a, b) for(i = a;i < b;i++)

int f[31], dp[31][13];

/**
	dp[a][b] = max(dp[c][b-1] + v[c+1][a])
	result: dp[29][12]
	restriction: a >= 0 && a <=29, b >=1 && b <=12
				 a + 1 >= b
	if b == 1, get the result directly.
**/

int getv(int a, int b)
{
	int rs = 0; int i = 1;
	for(;a <= b;a++, i++) rs += (i*f[a]);
	return rs;
}

void print(int a)
{
	if(a <= 25) cout<<(char)(a+'a');
	else if(a == 26) cout<<"+";
	else if(a == 27) cout<<"*";
	else if(a == 28) cout<<"/";
	else	cout<<"?";
}

void reback(int a, int b)
{
	if(b == 1) 
	{
	}
 	else
 	{
 		int c;FS(c,b-2,a)
 		{
 			/**c + 1 >= b - 1**/
 			if(dp[c][b-1] + getv(c+1,a) == dp[a][b])
 			{
 				reback(c,b-1); print(c+1); break;
 			}
 		}
 	}
}

int main()
{
	int t, M, i, j, c; cin >> t;
	while(t--)
	{
		cin >> M; string str;
		memset(f, 0, sizeof(f));
		memset(dp, 0, sizeof(dp));

		while(M--)
		{
			cin >> str;
			FF(i, str.size())
			{
				int c = str.at(i) - 'a';
				switch(str.at(i))
				{
				case '+': f[26]++; break;
				case '*': f[27]++; break;
				case '/': f[28]++; break;
				case '?': f[29]++; break;
				default : f[c]++;
				}
			}
		}
		FF(i, 30) FS(j, 1, min(i+2,13))
		{
			if(j == 1)
				dp[i][j] = getv(0,i);
			else
			{
				/**dp[i][j] = max(dp[c][j-1] + v[c+1][i])**/
				dp[i][j] = f[i] + dp[i-1][j-1]; FS(c,j-2,i)
				dp[i][j] = max(dp[i][j], getv(c+1,i) + dp[c][j-1]);
			}
		}
		reback(29,12);cout<<endl;
	}
}