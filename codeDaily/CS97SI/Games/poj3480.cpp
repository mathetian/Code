#include<iostream>
#include<stdio.h>
using namespace std;

/**
	Can't understand it.
**/
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,tp,c;
		scanf("%d",&n);
		tp=0;bool flag=false;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&c);
			if(c>1)flag=true;
			tp^=c;
		}
		if(flag)
		{
			if(tp)  printf("John\n");
			else printf("Brother\n");
		}
		else
		{
			if(n&1)  printf("Brother\n");
			else printf("John\n");
		}
	}

}