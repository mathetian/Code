#include <iostream>
using namespace std;

typedef long long int64_t;

int dfs(int64_t n)
{
	if(n < 10) return 1;
	else
	{
		int64_t a = n/2;
		if(n%2 != 0) a += 1;
		int64_t b = n/9;
		if(n%9 != 0) b += 1;
		if(dfs(a) && dfs(b)) return 0;
		return 1;
	}
	return 1;
}

int main()
{
	int64_t n;while(cin >> n)
	{
		int f = dfs(n);
		if(f == 1) cout << "Stan wins." << endl;
		else cout << "Ollie wins."<< endl;
	}
	return 0;
}