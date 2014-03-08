#include <iostream>
using namespace std;

#define FF(i,n) for(i = 0;i < n;i++)

int main()
{
	int n, a, i;
	while(cin>>n)
	{
		int rs = 0;
		FF(i,n)
		{
			cin>>a;rs ^= a;
		}
		if(rs != 0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}