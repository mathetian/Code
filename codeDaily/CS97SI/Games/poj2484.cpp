#include <iostream>
using namespace std;

/**
	Funny problem
**/

int main()
{
	int n; while(cin>>n)
	{
		if(n == 0) break;
		else if(n <= 2) cout<<"Alice"<<endl;
		else if(n == 3) cout<<"Bob"<<endl;
		else cout<<"Bob"<<endl;
	}
	return 0;
}