#include <string>
#include <iostream>
using namespace std;

#include <string.h>

void removeDuplicates(char*str)
{
	char*index=str; int s=0,i;
	while(*index!=0)
	{
		for(i=0;i<s&&(*(str+i))!=(*index);i++);
		if(i==s) str[s++]=*index;
		index++;
	}
	str[s++]=0;
}

int main()
{
	char flag[] ="abcadae";
	cout<<flag<<endl;
	removeDuplicates(flag);
	cout<<flag<<endl;
	return 0;
}