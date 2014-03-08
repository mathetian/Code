#include <iostream>
using namespace std;

/**
	a^b: c=(a^(b/2))^2
	if b%2==0, c  
	else, c=c*a;
**/
int pow(int a,int b)
{
	if(a==0) return 0;if(b==0) return 1;
	int c=pow(a,b/2);c=c*c;if(b%2==0) 
	return c;else return c*a;
}

/**version 2**/
/**why can't understand itkkk**/
/**You should understand how it works**/
/**a^b = a^x * a^x0 * a^x00 * a^x000 **/
/**a^x000 = (a^x00)^2**/
int pow(int a,int b)
{
	int rs=1;if(a==0)return 0;while(b)
	{ if(b%2==1) rs*=a;a*=a;b/=2; }
	return rs;
}

/**
	gcd(a,b)=gcd(b,a-b)
**/

int gcd(int a,int b)
{
	if(b==0) return a;
	if(a<b) return gcd(a,b);
	return gcd(b,a-b);
}

/**How to get it**/
int gcd(int a,int b)
{
	int r;while(b)
	{ r=a%b;a=b;b=r; }
	return r;
}

