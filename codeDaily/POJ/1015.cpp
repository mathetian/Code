#include<stdio.h>
#include<algorithm>
using  namespace std;

#define N 400

int appr[201];int defense[201];int n,m;
int v[201]; int p[201];
int plus2[21][2*N+1];int path[21][2*N+1][21];

int max2(int a,int b)
{
	return a>b?a:b;
}

void init()
{
	for(int i=0;i<21;i++)
		for(int j=0;j<=2*N;j++)
		{
			plus2[i][j]=-1;
			for(int k=0;k<21;k++)
				path[i][j][k]=0;
		}
	for(int i=1;i<=n;i++)
	{
		v[i]=appr[i]-defense[i];
		p[i]=appr[i]+defense[i];
	}
}

int main()
{
	int index=1;
	while(scanf("%d%d",&n,&m)&&n!=0)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",appr+i,defense+i);
		}
		init();
		for(int i=1;i<=n;i++)
		{
			int tmp=plus2[1][v[i]+N];
			if(tmp==-1)
			{
				plus2[1][v[i]+N]=p[i];
				path[1][v[i]+N][1]=i;
			}
			else if(p[i]>tmp)
			{
				plus2[1][v[i]+N]=p[i];
				path[1][v[i]+N][1]=i;
			}
		}
		int i,j,k;int a;
		if(m!=1)
		{
			for(i=2;i<=m;i++)
			{
				for(k=0;k<=800;k++)
				{
					for(j=1;j<=n;j++)
					{
					
						if(k<v[j])
							continue;
						if(plus2[i-1][k-v[j]]!=-1)
						{
							for(a=1;a<=i-1;a++)
							{
								if(j==path[i-1][k-v[j]][a])
								{
									break;
								}
							}
							//没有重复 不在i-1中
							//求最大的
							if(a==i)
								if(plus2[i][k]!=-1)
								{
									if(plus2[i][k]<plus2[i-1][k-v[j]]+p[j])
									{
										plus2[i][k]=plus2[i-1][k-v[j]]+p[j];
										path[i][k][i]=j;
										for(int b=1;b<i;b++)
											path[i][k][b]=path[i-1][k-v[j]][b];
									}
								}
								else
								{
									plus2[i][k]=plus2[i-1][k-v[j]]+p[j];
									path[i][k][i]=j;
									for(int b=1;b<i;b++)
										path[i][k][b]=path[i-1][k-v[j]][b];
								}
						}
					}
				}
			}
		}
		//处理比较plus2[m][k]按照题目要求的
		int a1=400;int cha=0;
		while(plus2[m][a1+cha]==-1&&plus2[m][a1-cha]==-1)
			cha++;
		printf("Jury #%d\n",index++); 
		int tmp3[21];

		if(plus2[m][a1+cha]==-1)
		{
			//int a2=a1+cha-400;
		//	int b2=plus2[m][a1+cha];
		//	printf("Best jury has value %d for prosecution and value %d for defence:\n",a2,b2);
			for(int i=1;i<=m;i++)
			{
				tmp3[i]=path[m][a1-cha][i];
			}
			//putchar('\n');

		}
		else if(plus2[m][a1-cha]==-1)
		{
		//	int a2=0-(a1-cha-400);
		//	int b2=plus2[m][a1-cha];
		//	printf("Best jury has value %d for prosecution and value %d for defence:\n",a2,b2);
		//	for(int i=1;i<=m;i++)
		//	{
		//		printf(" %d",path[m][a1-cha][i]);
		//	}
		//	putchar('\n');
			for(int i=1;i<=m;i++)
			{
				tmp3[i]=path[m][a1+cha][i];
			}
		}
		else if(plus2[m][a1+cha]<plus2[m][a1-cha])
		{
		//	int a2=0-(a1-cha-400);
		//	int b2=plus2[m][a1-cha];
		//	printf("Best jury has value %d for prosecution and value %d for defence:\n",a2,b2);
		//	for(int i=1;i<=m;i++)
		//	{
		//		printf(" %d",path[m][a1-cha][i]);
		//	}
		//	putchar('\n');
			for(int i=1;i<=m;i++)
			{
				tmp3[i]=path[m][a1-cha][i];
			}
		}
		else
		{
		//	int a2=a1+cha-400;
		//	int b2=plus2[m][a1+cha];
		//	printf("Best jury has value %d for prosecution and value %d for defence:\n",a2,b2);
		//	for(int i=1;i<=m;i++)
		//	{
		//		printf(" %d",path[m][a1+cha][i]);
		//	}
		//	putchar('\n');
			for(int i=1;i<=m;i++)
			{
				tmp3[i]=path[m][a1+cha][i];
			}
		}
		sort(tmp3+1,tmp3+m+1);
		int a2=0,b2=0;
		for(int i=1;i<=m;i++)
		{
			a2=a2+appr[tmp3[i]];
			b2=b2+defense[tmp3[i]];
		}
		printf("Best jury has value %d for prosecution and value %d for defence:\n",a2,b2);
		for(int i=1;i<=m;i++)
		{
			printf(" %d",tmp3[i]);
		}
		putchar('\n');
	}
	return 0;
}