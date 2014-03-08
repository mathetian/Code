#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define EPS 1e-8

typedef struct{
	double x;double y;
}POINT;

typedef struct{
	POINT p1,p2;
}LINE;

LINE lines[30];int used[30];POINT center;int wallNum;


int dmlcmp(double v1)
{
	if(fabs(v1)<EPS)
		return 0;
	return v1>0?1:-1;
}

int cross(double x1,double y1,double x2,double y2)
{
	int a=dmlcmp(x1*y2-x2*y1);
	return a;
}


int cross(POINT p1,POINT p2,POINT p3)
{
	int b=cross(p1.x-p2.x,p1.y-p2.y,p1.x-p3.x,p1.y-p3.y);
	return b;
}

int same_side(POINT p1,POINT p2,LINE l1)
{
	int c=cross(l1.p1,l1.p2,p1);int d=cross(l1.p1,l1.p2,p2);
	return c*d>=0;
	//return xmult(l.p1,p1,l.p2)*xmult(l.p1,p2,l.p2)>EPS; 
}

int segcrossSimple(POINT a,POINT b,POINT c,POINT d)
{
	return (cross(a,c,d)*cross(b,c,d)<0)&&(cross(c,a,b)*cross(d,a,b)<0);
}

double seg[4][100];int numSeg[4];

int dist(POINT p1,POINT p2)
{
	int ans=1;
	for(int i=0;i<wallNum;i++)
	{
		if(segcrossSimple(lines[i].p1,lines[i].p2,p1,p2))
			ans++;
	}
	return ans;
}

int main()
{
	while(scanf("%d",&wallNum)!=EOF)
	{
		for(int i=0;i<4;i++)
		{
			numSeg[i]=0;seg[i][numSeg[i]++]=0;
			seg[i][numSeg[i]++]=100;
		}
		for(int i=0;i<wallNum;i++)
		{
			scanf("%lf%lf%lf%lf",&lines[i].p1.x,&lines[i].p1.y,&lines[i].p2.x,&lines[i].p2.y);
			if(lines[i].p1.x==0&&(lines[i].p1.y==0||lines[i].p1.y==100))
				goto label1;
			else if(lines[i].p1.x==100&&(lines[i].p1.y==0||lines[i].p1.y==100))
				goto label1;
			if(lines[i].p1.x==0)
				seg[0][numSeg[0]++]=lines[i].p1.y;
			else if(lines[i].p1.x==100)
				seg[2][numSeg[2]++]=lines[i].p1.y;
			else if(lines[i].p1.y==0)
				seg[3][numSeg[3]++]=lines[i].p1.x;
			else
				seg[1][numSeg[1]++]=lines[i].p1.x;
label1:;
			if(lines[i].p2.x==0&&(lines[i].p2.y==0||lines[i].p2.y==100))
				continue;
			else if(lines[i].p2.x==100&&(lines[i].p2.y==0||lines[i].p2.y==100))
				continue;
			if(lines[i].p2.x==0)
				seg[0][numSeg[0]++]=lines[i].p2.y;
			else if(lines[i].p2.x==100)
				seg[2][numSeg[2]++]=lines[i].p2.y;
			else if(lines[i].p2.y==0)
				seg[3][numSeg[3]++]=lines[i].p2.x;
			else
				seg[1][numSeg[1]++]=lines[i].p2.x;
		}
		sort(seg[0],seg[0]+numSeg[0]);
		sort(seg[1],seg[1]+numSeg[1]);
		sort(seg[2],seg[2]+numSeg[2]);
		sort(seg[3],seg[3]+numSeg[3]);
		scanf("%lf%lf",&center.x,&center.y);
		int min=100000;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<numSeg[i]-1;j++)
			{
				POINT tmp2;
				double mid=(seg[i][j]+seg[i][j+1])/2.0;
				switch(i)
				{
				case 0: tmp2.x=0;tmp2.y=mid;;break;
				case 1: tmp2.y=100;tmp2.x=mid;break;
				case 2: tmp2.x=100;tmp2.y=mid;;break;
				case 3: tmp2.x=mid;tmp2.y=0;break;
				}
				int now=dist(tmp2,center);
				if(min>now)
					min=now;
			}
		}
		printf("Number of doors = %d\n",min);
	}
}