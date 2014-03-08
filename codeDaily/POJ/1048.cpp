#include<stdio.h>
#include<string.h>

char maps[110][110];
int height;
char input[110];

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

int able(int x,int y)
{
	if(x>=0&&y>=0)
	{
		if(x<110&&y<110)
		{
			if(maps[x][y]!=' ')
				return 1;
		}
	}
	return 0;
}

int process(int sx,int sy,int flag)
{
	int a,b;
	switch(maps[sx][sy])
	{
	case '+':
		if(flag==UP||flag==DOWN)
		{
			if(able(sx,sy-1)&&maps[sx][sy-1]=='-')
			{
				a=process(sx,sy-1,LEFT);
				
				return a;
			}
			else if(able(sx,sy+1)&&maps[sx][sy+1]=='-')
			{	
				a=process(sx,sy+1,RIGHT);
				return a;
			}
		}
		else
		{
			if(able(sx-1,sy)&&maps[sx-1][sy]=='|')
			{
				a=process(sx-1,sy,UP);
				return a;
			}
			else if(able(sx+1,sy)&&maps[sx+1][sy]=='|')
			{
				a=process(sx+1,sy,DOWN);
				return a;
			}
		}
		
		break;

	case '-':
		if(flag==LEFT&&able(sx,sy-1))
		{
			a=process(sx,sy-1,LEFT);
			return a;
		}
		else if(flag==RIGHT&&able(sx,sy+1))
		{
			a=process(sx,sy+1,RIGHT);
			return a;
		}
		break;
	case '|':
		if(flag==UP&&able(sx-1,sy))
		{
			a=process(sx-1,sy,UP);
			return a;
		}
		else if(flag==DOWN&&able(sx+1,sy))
		{
			a=process(sx+1,sy,DOWN);
			return a;
		}
		break;
	case 'o':
		a=!process(sx,sy-1,LEFT);
		return a;break;
	case '>':
		a=process(sx-1,sy-3,LEFT);b=process(sx+1,sy-3,LEFT);
		return a | b;break;
	case ')':
		a=process(sx-1,sy-3,LEFT);
		b=process(sx+1,sy-3,LEFT);
	//	printf("%d  %d\n",a,b);
		return a & b;break;;
	default: 
		a=input[maps[sx][sy]-'A']-'0';
	//	printf("%d\n",a);
		return a;
	}
}

int main()
{
	while(gets(input))
	{
		height=0;
		memset(maps,0,110*110);
		strcpy(maps[0],input);
		height++;
		while(gets(input)&&strcmp(input,"*")!=0)
		{
			strcpy(maps[height],input);height++;
		}
		int orgx;int orgy;
		for(int i=0;i<110;i++)
		{
			for(int j=0;j<110;j++)
			{
				if(maps[i][j]=='?')
				{
					orgx=i;orgy=j;break;
				}
			}
		}
		while(gets(input)&&strcmp(input,"*")!=0)
		{
			int ans;
			if(able(orgx,orgy-1)&&maps[orgx][orgy-1]=='-')
				ans=process(orgx,orgy-1,LEFT);
			else if(able(orgx,orgy+1)&&maps[orgx][orgy+1]=='-')
				ans=process(orgx,orgy+1,RIGHT);
			else if(able(orgx-1,orgy)&&maps[orgx-1][orgy]=='|')
				ans=process(orgx-1,orgy,UP);
			else if(able(orgx+1,orgy)&&maps[orgx+1][orgy]=='|')
				ans=process(orgx+1,orgy,DOWN);
			printf("%d\n",ans);
		}
		printf("\n");
	}
	return 0;
}