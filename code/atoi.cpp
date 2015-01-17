#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>

#undef atoi
#undef strtol

bool isDigital(char c)
{
	if(c>='0'&&c<='9')
		return true;
	return false;
}

long int strtol(const char *nptr, char **endptr, int base)
{
	const char *p=nptr; int rs=0;
	int flag=(*p=='-')?-1:1;

	if(*p=='+'||*p=='-') p++;
	
	while((*p)!=0&&isDigital(*p)) 
		rs=rs*10+(*p++)-'0';
	
	return rs;
}

//strtol(nptr, NULL, 10) 
int atoi(const char*nptr)
{
	return strtol(nptr, NULL, 10);	
}

int main()
{
	cout<<atoi("123a123abc")<<endl;
	return 0;
}
