#include<stdio.h>
#include<math.h>
typedef struct{
	int x,y,z;
}POINT;

POINT points[16];
POINT input;

int dist(POINT p1,POINT p2)
{
	return pow((double)p1.x-p2.x,2)+pow((double)p1.y-p2.y,2)+pow((double)p1.z-p2.z,2);
}

int main()
{
	for(int i=0;i<16;i++)
		scanf("%d%d%d",&points[i].x,&points[i].y,&points[i].z);
	while(scanf("%d%d%d",&input.x,&input.y,&input.z))
	{
		if(input.x==-1&&input.y==-1&&input.z==-1)
			break;
		int minDist=-1;int index=0;
		for(int i=0;i<16;i++)
		{
			int tmp=dist(input,points[i]);
			if(minDist>tmp||minDist==-1)
			{
				minDist=tmp;index=i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",input.x,input.y,input.z,points[index].x,points[index].y,points[index].z);
	}
	return 0;
}