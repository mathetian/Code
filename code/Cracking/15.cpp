#include <iostream>
#include <string>
using namespace std;

#include <string.h>

void replace(char*str)
{
	int c=0,l=0; while(str[l]!=0)
	{ if(str[l]==' ') c++; l++; }
	int nl=l+2*c;str[nl]=0;l--;
	nl--;
	while(l>=0)
	{	
		if(str[l]==' ')
		{
			str[nl-2]='a';
			str[nl-1]='b';
			str[nl]='c';
			nl=nl-3;
		}
		else str[nl--]=str[l];
		l--;
	}
}

int main()
{
	char flag[50]="abc de ad ";
	replace(flag);
	cout<<flag<<endl;
	return 0;
}