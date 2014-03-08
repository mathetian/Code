#include<stdio.h>
int main()
{
	float s = 0.0 ,sum ,k;
	int i ;
	for(i = 0; i <12; i++)
	{
		scanf("%f",&k);
		sum += k;
	}
	printf("$%0.2f\n",sum / 12.0);
	return 0;
}