#include<stdio.h>
#include<string.h>

#define BEGY 1900
#define BEGM 1
#define BEGD 1

#define ENDY 2001
#define ENDM 11
#define ENDD 4

#define LOSER 0
#define WINNER 1

typedef struct{
	int yy;int mm;int dd;
}DAY;

int day[2005][13][32];

int isLess(DAY now)
{
	if(now.yy>BEGY)
		return 0;
	else if(now.yy<BEGY)
		return 1;
	else
	{
		if(now.mm>BEGM)
			return 0;
		else if(now.mm<BEGM)
			return 1;
		else
		{
			if(now.dd>BEGD)
				return 0;
			return 1;
		}
	}
}

int isLeap(int year)
{
	if(year%4==0)
	{
		if(year%400==0)
			return 1;
		else
		{
			if(year%100==0)
				return 0;
		}
		return 1;
	}
	return 0;
}

DAY getPrevD(DAY now)
{
	if(now.dd>1)
		now.dd--;
	else
	{
		if(now.mm==1)
		{
			now.yy-=1;now.mm=12;now.dd=31;
		}
		else if(now.mm==3)
		{
			now.mm=2;
			if(isLeap(now.yy)==1)
				now.dd=29;
			else
				now.dd=28;
		}
		else
		{
			if(now.mm==2||now.mm==4||now.mm==6||now.mm==8||now.mm==9||now.mm==11)
				now.dd=31;
			else
				now.dd=30;
			now.mm-=1;
		}	
	}
	return now;
}

DAY getPrevM(DAY now)
{
	if(now.mm==1)
	{
		now.mm=12;now.yy-=1;
		return now;
	}

	if(now.dd<=28)
		now.mm-=1;
	else
	{
		if(now.dd==29)
		{
			if(now.mm==3)
			{
				if(isLeap(now.yy)==1)
					now.mm-=1;
				else
					now.mm=-1;
			}
			else
				now.mm-=1;
		}
		else if(now.dd==30)
		{
			if(now.mm==3)
				now.mm=-1;
			else
				now.mm-=1;
		}
		else if(now.dd==31)
		{
			if(now.mm==8)
				now.mm-=1;
			else
				now.mm=-1;
		}
	}
	return now;
}

int isWinner(DAY now)
{
	return day[now.yy][now.mm][now.dd]==WINNER?1:0;
}

int main()
{
	memset(day,0,sizeof(int)*2005*13*32);
	day[ENDY][ENDM][ENDD]=LOSER;
	DAY now={ENDY,ENDM,ENDD};
	while(1)
	{
		if(now.mm==8&&now.dd<3)
			while(0);
		if(isLess(now))
			break;
		if(now.yy<10)
			while(0);
		DAY prev;
		prev=getPrevM(now);
		if(prev.mm!=-1)
			day[prev.yy][prev.mm][prev.dd]=WINNER;
		prev=getPrevD(now);
		day[prev.yy][prev.mm][prev.dd]=WINNER;
		if(prev.yy<0)
			while(0);
		DAY prev2;
		while(isWinner(prev))
		{
			if(isLess(prev))
				break;
			prev=getPrevD(prev);
		}
		now=prev;
	}
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		DAY start;
		scanf("%d%d%d",&start.yy,&start.mm,&start.dd);
		if(day[start.yy][start.mm][start.dd]==LOSER)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}