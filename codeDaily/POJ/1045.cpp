#include<stdio.h>
#include<math.h>

int main()
{
	double Vs,R,C;int cases;
	scanf("%lf%lf%lf%d",&Vs,&R,&C,&cases);
	while(cases--)
	{
		double omega;
		scanf("%lf",&omega);
		double ans=C*R*omega*Vs/(sqrt(1+(C*R*omega)*(C*R*omega)));
		printf("%0.3f\n",ans);
	}
	return 0;
}