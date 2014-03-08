#include<stdio.h>
#include<math.h>

const double precision=1e-3;   //精度限制  
const double inf=99999.0;   //正无穷，注意下面使用的是负无穷  

int dblcmp(double d)
{
	if(fabs(d)<precision)
		return 0;
	else
		return d>0?1:-1;
}

typedef struct{
	double x,y;
}Point;

double det(double x1,double y1,double x2,double y2)
{
	return x1*y2-x2*y1;
}

double cross(Point a,Point b,Point c)
{
	return det(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}

int check(Point a,Point b,Point c,Point d)
{
	return (dblcmp(cross(a,b,c))*dblcmp(cross(a,b,d))<=0);
}

double segCross(Point a,Point b,Point c,Point d)
{
	double s1,s2;
	s1=cross(a,b,c);s2=cross(a,b,d);
	int d1,d2;d1=dblcmp(s1);d2=dblcmp(s2);
	if(d1*d2<0)
		return (c.x*s2-d.x*s1)/(s2-s1);
	if(d1*d2==0)
	{
		if(d1==0)
			return c.x;
		else
			return d.x;
	}
	return -inf;
}

Point up[21];Point down[21];

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int pointNum;
	while(scanf("%d",&pointNum)&&pointNum!=0)
	{
		for(int i=0;i<pointNum;i++)
		{
			scanf("%lf%lf",&up[i].x,&up[i].y);
			down[i].x=up[i].x;down[i].y=up[i].y-1;
		}
		int i,j,k;int flag=0;double ans=-inf;
		for(i=0;i<pointNum&&flag==0;i++)
		{
			for(j=0;j<pointNum;j++)
			{
				if(i==j)
					continue;
				for(k=0;k<pointNum;k++)
				{
					if(check(up[i],down[j],up[k],down[k])==0)
						break;
				}
				if(k==pointNum)
				{
					flag=1;break;
				}
				if(k>max(i,j))
				{
					double tmp=segCross(up[i],down[j],up[k],up[k-1]);
					if(tmp>ans)
						ans=tmp;
					tmp=segCross(up[i],down[j],down[k],down[k-1]);
					if(tmp>ans)
						ans=tmp;
				}
			}
		}
		if(flag==1)
			printf("Through all the pipe.\n");
		else
			printf("%.2f\n",ans);
	}
	return 0;
}