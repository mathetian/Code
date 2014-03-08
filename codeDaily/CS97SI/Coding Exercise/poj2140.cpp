#include <iostream>
#include <math.h>
using namespace std;

/**
	n*a+(1+..+n-1)=n*a+n*(n-1)/2;
	n*a+n*(n-1)/2 = b
**/
/**Another persperctive**/
int getn(int b)
{
	int count=0,n=1;
	for(;n*(n-1)/2<b;n++)
	if((b-n*(n-1)/2)%n==0) 
	count++;return count;
}

int main()
{
	int n;cin>>n;
	cout<<getn(n)<<endl;
	return 0;
}