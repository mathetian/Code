#include <vector>
#include <string>
using namespace std;

typedef struct{
	int color;
	int64 value;
}ELEM;

void getMM(int64 r,int64 g,int64 b,ELEM &mv,ELEM &smv)
{
	if(r<=g&&r<=b)
	{
		mv.value=r;mv.color=0;
		if(g<=b) {smv.color=1;smv.value=g;}
		else {smv.color=2;smv.value=b;}
	}
	else if(g<=r&&g<=b)
	{
		mv.value=g;mv.color=1;
		if(r<=b) {smv.color=0;smv.value=r;}
		else {smv.color=2;smv.value=b;}
	}
	else if(b<=r&&b<=g)
	{
		mv.value=b;mv.color=2;
		if(r<=g) {smv.color=0;smv.value=r;}
		else {smv.color=1;smv.value=g;}
	}
}

string colors[]={"BLUE","RED","GREEN"};

string getColor(int64 r,
                int64 g,
                int64 b,
                int64 k) {
    ELEM mv,smv;
    getMM(r,g,b,mv,smv);
    if(k<=3*mv.value)
    {
    	k=k%3;
    	//0 blue, 1 RED, 2 GREEN
    	return colors[k];
    }
    else
    {
    	k-=3*mv.value;
    	smv.value-=mv.value;
    	if(smv.value!=0&&k<=2*smv.value)
    	{
    		k=k%2;
    		if(mv.color==0)
    		{
    			//0 BLUE 1 RED
    			if(k==0) return colors[0];
    			else return colors[2];
    		}
    		else if(mv.color==1)
    		{
    			if(k==0) return colors[0];
    			else return colors[1];
    		}
    		else
    		{
    			if(k==0) return colors[2];
    			return colors[1];
    		}
    	}
    	else
    	{
    		if(mv.color!=0&&smv.color!=0) return colors[1];
    		if(mv.color!=1&&smv.color!=1) return colors[2];
    		return colors[0];
    	}
    }
    return "$";
}
