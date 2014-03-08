#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int s,n;
typedef struct{
	char data[25][15];
}NODE;

NODE nodes[10];int width;int height;

//char result[][15];
void init_0()
{
	for(int i=1;i<=s;i++)
	{
		nodes[0].data[0][i]='-';
		nodes[0].data[2*s+2][i]='-';
		
		nodes[0].data[i][0]='|';
		nodes[0].data[i][width-1]='|';

		nodes[0].data[s+1+i][0]='|';
		nodes[0].data[s+1+i][width-1]='|';
	}
}

void init_1()
{
	for(int i=1;i<=s;i++)
	{
		nodes[1].data[i][s+1]='|';
		nodes[1].data[s+1+i][s+1]='|';
	}
}

void init_2()
{
	for(int i=1;i<=s;i++)
	{
		nodes[2].data[0][i]='-';
		nodes[2].data[s+1][i]='-';
		nodes[2].data[2*s+2][i]='-';

		nodes[2].data[i][s+1]='|';
		nodes[2].data[s+1+i][0]='|';
	}
}

void init_3()
{
	for(int i=1;i<=s;i++)
	{
		nodes[3].data[0][i]='-';
		nodes[3].data[s+1][i]='-';
		nodes[3].data[2*s+2][i]='-';

		nodes[3].data[i][s+1]='|';
		nodes[3].data[s+1+i][s+1]='|';
	}
}

void init_4()
{
	for(int i=1;i<=s;i++)
	{
		nodes[4].data[s+1][i]='-';
		
		nodes[4].data[i][0]='|';
		nodes[4].data[i][s+1]='|';

		nodes[4].data[s+1+i][s+1]='|';
	}
}

void init_5()
{
	for(int i=1;i<=s;i++)
	{
		nodes[5].data[0][i]='-';
		nodes[5].data[s+1][i]='-';
		nodes[5].data[2*s+2][i]='-';

		nodes[5].data[i][0]='|';
		nodes[5].data[s+1+i][s+1]='|';
	}
}

void init_6()
{
	for(int i=1;i<=s;i++)
	{
		nodes[6].data[0][i]='-';
		nodes[6].data[s+1][i]='-';
		nodes[6].data[2*s+2][i]='-';

		nodes[6].data[i][0]='|';
		nodes[6].data[s+1+i][0]='|';
		nodes[6].data[s+1+i][s+1]='|';
	}
}

void init_7()
{
	for(int i=1;i<=s;i++)
	{
		nodes[7].data[i][s+1]='|';
		nodes[7].data[s+1+i][s+1]='|';
	}
	for(int i=1;i<=s;i++)
		nodes[7].data[0][i]='-';	
}

void init_8()
{
	for(int i=1;i<=s;i++)
	{
		nodes[8].data[0][i]='-';
		nodes[8].data[s+1][i]='-';
		nodes[8].data[2*s+2][i]='-';

		nodes[8].data[i][s+1]='|';nodes[8].data[i][0]='|';
		nodes[8].data[s+1+i][s+1]='|';nodes[8].data[s+1+i][0]='|';
	}
}

void init_9()
{
	for(int i=1;i<=s;i++)
	{
		nodes[9].data[0][i]='-';
		nodes[9].data[s+1][i]='-';
		nodes[9].data[2*s+2][i]='-';

		nodes[9].data[i][s+1]='|';nodes[9].data[i][0]='|';
		nodes[9].data[s+1+i][s+1]='|';//nodes[8].data[s+1+i][0]='|';
	}
}

void init()
{
	init_0();init_1();init_2();init_3();init_4();init_5();init_6();init_7();init_8();init_9();
}

int val[100];int valLen;
int main()
{
	while(scanf("%d%d",&s,&n))
	{
		if(s==0&&n==0)
			break;
		width=s+2;height=2*s+3;
		memset(nodes,' ',sizeof(NODE)*10);
		init();
		valLen=0;
		if(n==0)
		{
			for(int i=0;i<height;i++)
			{
				for(int k=0;k<width;k++)
					putchar(nodes[0].data[i][k]);
				putchar('\n');
			}
			putchar('\n');
			continue;
		}


		while(n!=0)
		{
			val[valLen++]=n%10;n=n/10;
		}
		reverse(val,val+valLen);
		for(int i=0;i<height;i++)
		{
			for(int j=0;j<valLen;j++)
			{
				for(int k=0;k<width;k++)
					putchar(nodes[val[j]].data[i][k]);
				if(j==valLen-1)
					putchar('\n');
				else
					putchar(' ');
			}
		}
		putchar('\n');
	}
	return 0;
}