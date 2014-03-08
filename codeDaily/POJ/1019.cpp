
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef long long ll;

char posAns[145335];int posA;

void insertPos(int val)
{
	char tmp[6];
	memset(tmp,'\0',6);
	sprintf(tmp,"%d",val);
	strcat(posAns,tmp);
}

void insertPosA(int n)
{
	 char temp[6];
        int pos=0;
        while( n>9 ){
                temp[pos++]=n%10+'0';
                n/=10;
        }
        temp[pos++]=n+'0';
        temp[pos]='\0';
		while(pos--) 
			posAns[posA++]=temp[pos];
		posAns[posA]='\0';
}
ll get_len(ll val)
{
	ll num=1;
	while(val/10)
	{
		val=val/10;
		num++;
	}
	return num;
}

int main()
{
	memset(posAns,'\0',145335);posA=0;
	for(int i=1;i<=31278;i++)
	{
		insertPosA(i);//printf("%d  ",i);
	}
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		ll input;
		scanf("%lld",&input);
		ll valNow=1;
		ll num=0;ll oldlen=0;
		while(num<input)
		{
			int tmp2=get_len(valNow);
			oldlen=oldlen+tmp2;
			num+=oldlen;
			valNow++;
		}
		num=num-oldlen;
		printf("%c\n",posAns[input-num-1]);
	}
	return 0;
}
