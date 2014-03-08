#include<stdio.h>

typedef long long LL;

void GCDSL(LL a,LL b,LL&x,LL&y)
{
	if(b==0)
	{
		x=1;y=0;return;
	}
	GCDSL(b,a%b,x,y);
	LL t=y;
	y=x-(a/b)*y;
	x=t;
}

int GCD(LL a,LL b)
{
	if(b==0)
		return a;
	else
		return GCD(b,a%b);
}

int main()
{
	LL x,y,m,n,l;
	while(scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l)!=EOF)
	{
		LL c=x-y;LL a=l;LL b=n-m;
		LL d=GCD(a,b);
		if(c%d!=0)
			printf("Impossible\n");
		else
		{
			a=a/d;b=b/d;c=c/d;
			GCDSL(a,b,x,y);
			y=c*y;
			//LL t=y/a;
			//y=y-t*a;
			while(y>0)
				y-=a;
			while(y<0)
				y+=a;
			printf("%lld\n",y);
		}
	}
	
	return 0;
}