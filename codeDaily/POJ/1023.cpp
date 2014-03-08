#include<stdio.h>

typedef long long ll;
int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		int len;char input[64];ll n;
		scanf("%d%s%lld",&len,input,&n);
		while(len)
		{
			if(n&0x01)
			{
				n+=(input[len-1]=='p'?-1:1);
				input[len-1]='1';
			}
			else
				input[len-1]='0';
			n=n>>1;
			len--;
		}
		puts(n?"Impossible":input);
	}
	return 0;
}