#include<stdio.h>
#include<math.h>

int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		int nums;
		scanf("%d",&nums);
		int dif1=0;int dif2=0;
		for(int i=0;i<nums;i++)
		{
			int tmp;
			scanf("%d",&tmp);
			if(tmp==1)
			{
				if(i%2==0)
					dif1++;
				else
					dif2++;
			}
		}
		if(nums%2==1||abs(dif1-dif2)<2)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}