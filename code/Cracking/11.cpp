#include <string>
#include <iostream>
using namespace std;

#include <string.h>

bool duplicateString(string str)
{
	unsigned char flags[32];
	memset(flags, 0, sizeof(flags));
	for(int i=0;i<str.size();i++)
	{
		int b = str.at(i)/8;
		int c = str.at(i)%8;
		if((flags[b]&(1<<c))!=0) return true;
		flags[b]|=(1<<c);
	}
	return false;
}

int main()
{
	cout<<duplicateString("abAbA")<<endl;
	return 0;
}