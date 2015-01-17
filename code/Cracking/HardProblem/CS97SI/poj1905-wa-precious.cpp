#include <iostream>
using namespace std;

#include <math.h>

int main()
{
	double l, n, coff;
	while(cin>>l>>n>>coff)
	{
		if(fabs(l+1.0) < 0.0001) break;
		if(l==0||n==0||coff==0)
		{
			printf("%0.3f\n",0.00);
			continue;
		}
		double ll = (1+n*coff)*l;
		double low = 0, high = 0x3ffff;

		while(high-low>1e-12)
		{
			double mid = (low+high)/2;
			double deg = 2*asin(0.5*l/mid);
			double rr = deg*mid;
			if(fabs(ll-rr) < 0.0001)
			{
				double f = mid - sqrt(mid*mid - 0.25*l*l);
				printf("%0.3f\n",f);
				break;
			}
			else if(rr > ll) low = mid;
			else high = mid;
		}

		if(low >= high)
		{
			printf("%0.3f\n",0.00);
		}
	}
	return 0;
}