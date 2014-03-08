#include<stdio.h>
#include<string.h>

int main()
{
	// pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu
	char*str[]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet "};
	char*stl[]={ "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
	int nums;
	scanf("%d",&nums);
	printf("%d\n",nums);
	while(nums--)
	{
		//NumberOfTheDay. Month Year 
		int day,year;
		char month[10];
		scanf("%d.",&day);
		scanf("%s",month);
		scanf("%d",&year);
		int days=0;
		days=days+year*365;
		int i;
		for(i=0;i<18;i++)
		{
			if(strcmp(str[i],month)==0)
			{
				days=days+i*20;
				break;
			}
		}
		if(i==18)
		{
			days=days+18*20;
		}
		days=days+day;
		year=days/260;
		days%=260;
		int a;char t1[10];
		a=days%13+1;
		strcpy(t1,stl[days%20]);
		printf("%d %s %d\n",a,t1,year);
	}
	return 0;
}