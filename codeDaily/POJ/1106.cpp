#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MXNUM 1000
#define MAX(a,b) a>b?a:b

struct POINT_t{
	int x,y;
	double degree;
};
typedef struct POINT_t POINT;

POINT points[MXNUM];

//int (*compar)(const void *, const void *));

int compar(const void*p1,const void*p2)
{
	POINT point1=*((POINT*)p1);POINT point2=*((POINT*)p2);
	if(point1.degree<point2.degree)
		return -1;
	else if(point1.degree==point2.degree)
		return 0;
	else
		return 1;
}

int main()
{
	int x,y;double r,r2;int numbers;int i,j,k;int mxExpt;
	double startDegree,endDegree;
	const double PI = atan(1.0)*4;
	while(scanf("%d%d%lf",&x,&y,&r))
	{
		if(r<0)
			break;
		scanf("%d",&numbers);j=0;r2=r*r;
		mxExpt=0;
		for(i=0;i<numbers;i++)
		{
			scanf("%d%d",&points[j].x,&points[j].y);
			points[j].x-=x;points[j].y-=y;
			if(points[j].x*points[j].x+points[j].y*points[j].y>r2)
				continue;
			points[j].degree=atan2((double)points[j].y,(double)points[j].x);
			if(points[j].degree<0)
				points[j].degree+=2*PI;
			j++;
		}
		qsort(points,j,sizeof(POINT),compar);
		for(i=0;i<j;i++)
		{
			startDegree=points[i].degree;
			int num=0;
			if(startDegree<PI)
			{
				endDegree=points[i].degree+PI;
				for(k=i;k<j;k++)
				{
					if(points[k].degree<=endDegree)
						num++;
					else
						break;
				}
					
			}
			else
			{
				endDegree=points[i].degree-PI;
				for(k=i;k<j;k++)
				{
					if(points[k].degree<2*PI)
						num++;
					else
						break;
				}
				for(k=0;k<i;k++)
				{
					if(points[k].degree<=endDegree)
						num++;
					else
						break;
				}
			}
			mxExpt=MAX(mxExpt,num);
		}
		printf("%d\n",mxExpt);
	}
	return 0;
}