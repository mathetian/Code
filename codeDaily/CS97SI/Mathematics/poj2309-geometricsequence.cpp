#include <iostream>
using namespace std;

/**
	Mathematic problem
**/

typedef long long int64;

int64 pow(int a,int b)
{
	int64 rs=1;if(a==0)return 0;while(b)
	{ if(b%2==1) rs*=a;a*=a;b/=2; }
	return rs;
}

int main()
{
	int n;int64 m;cin>>n;
	while(n--)
	{
		cin>>m;int n1=0;int64 k=m;
		while(k%2==0){n1++;k>>=1;}
		int64 l1=m-pow(2,n1)+1;
		int64 l2=m+pow(2,n1)-1;
		cout<<l1<<" "<<l2<<endl;
	}
	return 0;
}