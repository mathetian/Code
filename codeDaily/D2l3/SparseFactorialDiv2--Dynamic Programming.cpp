#include <vector>
#include <string>
#include <set>
using namespace std;

/*int64 getCount(int64 lo, int64 hi, int64 divisor) 
{
	int64 i;int64 rs=0;
	for(i=lo;i<=hi;i++)
	{
		int64 r=0;
		while(r*r<i)
		{		
			int64 r1=2, r2=i-r*r;
			while(r1<divisor&&r1<r2)
			{
				while(r2%r1==0) r2/=r1;
				r1++;
			}
			if(r1==divisor)
			{
				if(r2%divisor==0)
				{
					//ok
					rs++;break;
				}
			}
			r++;
		}	
	}
    return rs;
}*/

int64 get(int64 num,int64 divisor)
{
	int64 i;set<int64> is;int64 rs=0;
	for(i=0;(i*i)<num;i++)
	{
		int64 j=(i*i)%divisor;
		if(is.find(j)!=is.end()) continue;
		is.insert(j);rs+=(num-i*i)/divisor;
	}
	return rs;
}

int64 getCount(int64 lo, int64 hi, int64 divisor) 
{ 
	return get(hi,divisor)-get(lo-1,divisor);
}
