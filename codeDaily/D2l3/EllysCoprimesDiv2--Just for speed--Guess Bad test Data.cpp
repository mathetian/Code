#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int get(int a,int b)
{
	//cout<<a<<" "<<b<<endl;
	if(gcd(a,b)==1) return 0;
	vector<int> dp(b-a+1,0x3fffff);int i,j;
	dp[0]=0;
	for (i=a+1; i<b; i++) {
	        if ( gcd(a,i) == 1 && gcd(i,b) == 1) {
	            // just adding i is good enough
	            return 1;
	        }
	}

	for(i=a+1;i<=b;i++)
	{
		for(j=a;j<i;j++)
		{
			if(gcd(i,j)==1) 
				dp[i-a]=min(dp[i-a],dp[j-a]+1);
		}
		//cout<<i<<" "<<dp[i-a]<<")";
	}
	return dp.at(b-a)-1;
}

int getCount(vector<int> const &numbers) 
{
	vector<int> num(numbers.begin(),numbers.end());
	int i;sort(num.begin(),num.end());int n=0;
	for(i=1;i<num.size();i++) n+=get(num.at(i-1),num.at(i));
    return n;
}

/*int main()
{
	int nn[]={7, 42};vector<int> num2(nn,nn+2);
	cout<<getCount(num2)<<endl;
	return 0;
}*/

/*	int gcd(int x, int y)
{
    while (y > 0) {
        int z = y;
        y = x % y;
        x = z;
    }
    return x;
}

int minimumFill(int a, int b)
{
    if (gcd(a,b) == 1) { 
        //easy, we do not need to add anything else
        return 0;
    } else {
        for (int i=a+1; i<b; i++) {
            if ( gcd(a,i) == 1 && gcd(i,b) == 1) {
                // just adding i is good enough
                return 1;
            }
        }
        //return 2; //This is correct but  let us try
                   // the dynamic programming method instead:.  
                   
                   
        // { b - a < 175 }
        
        int dp[b - a + 1];
        dp[b - a] = 1;
        for (int i = b - 1; i >= a; i--) {
            dp[i - a] = 1000;
            for (int j = i + 1; j <= b; j++) {
                if (gcd(i, j) == 1) {
                    dp[i - a] = std::min(dp[i - a], 1 + dp[j - a] );
                }
            }
        }
        return dp[a - a] - 2;
    }
}

int getCount(vector <int> numbers)
{
    sort(numbers.begin(), numbers.end());
    int res = 0;
    for (int i=1; i<numbers.size(); i++) {
        res += minimumFill(numbers[i-1], numbers[i]);
    }
    return res;
}*/