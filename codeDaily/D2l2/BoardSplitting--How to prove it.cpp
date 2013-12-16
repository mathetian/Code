#include <vector>
#include <string>
using namespace std;

/*int minimumCuts(int desiredLength, int desiredCount, int actualLength) 
{
	if(actualLength<desiredLength)
	{
		//`desiredCount` need to be filled
		//each has space `r`
		//there are `m` stock for space
		//each actual stock can fill `div` virtual stock
		int n=(desiredLength*desiredCount)/actualLength;
		if((desiredLength*desiredCount)%actualLength!=0) n+=1;
		int m=n-((int)desiredLength/actualLength)*desiredCount;
		int r = desiredLength-((int)desiredLength/actualLength)*actualLength;
		if(r==0) return 0;
		int div=actualLength/r;
		//if no more for subspace
		if(actualLength%r==0)
		{
			if((m*div)==desiredCount) return (div-1)*m;
			else
			{
				int r1=(m-1)*(div-1);
				int r2=desiredCount-div*(m-1);
				return r1+r2;
			}
			return 0;
		}
		else
		{
			//Todo
		}
	}
	else
	{
		int r=desiredLength-((int)desiredLength/actualLength)*actualLength;
		if(r==0) return 0;
		int m=(r*desiredCount)/actualLength;
		if((r*desiredCount)%actualLength!=0) m+=1;
		int div=actualLength/r;
		if(actualLength%r==0)
		{
			if((m*div)==desiredCount) return (div-1)*m;
			else
			{
				int r1=(m-1)*(div-1);
				int r2=desiredCount-div*(m-1);
				return r1+r2;
			}
			return 0;
		}
		else
		{
			//Todo
		}
		
	}
    return 0;
}*/

int minimumCuts(int desiredLength, int desiredCount, int actualLength) 
{
	//hard to prove
	int r=0;int s=0;
	while(desiredCount--)
	{
		while(s<desiredLength) s+=actualLength;
		s-=desiredLength;
		if(s>0) r++;
	}
	return r;
}
