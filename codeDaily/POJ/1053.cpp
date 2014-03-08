#include<stdio.h>
#include<string.h>
char input[100][10];int n;

int main()
{
	char tmp[10];
	while(gets(tmp))
	{
		strcpy(input[0],tmp);n=1;
		while(gets(tmp)&&strcmp(tmp,""))
			strcpy(input[n++],tmp);
		printf("CARDS:  ");
		for(int i=0;i<n-1;i++)
			printf("%s ",input[i]);
		printf("%s\n",input[n-1]);
		int index=1;
		int flag=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int k=j+1;k<n;k++)
				{
					int m;
					for(m=0;m<4;m++)
					{
						if(input[i][m]==input[j][m]&&input[j][m]==input[k][m])
							continue;
						else
						{
							if(input[i][m]==input[j][m]||input[i][m]==input[k][m]||input[j][m]==input[k][m])
								break;
						}
					}
					if(m==4)
					{
						if(flag==0)
							printf("SETS:   %d.  %s %s %s\n",index++,input[i],input[j],input[k]);
						else
							printf("        %d. %s %s %s\n",index++,input[i],input[j],input[k]);
						flag=1;
					}
				}
			}
		}
		if(index==1)
			printf("SETS:   *** None Found ***\n");
		printf("\n");
	}
	return 0;
}