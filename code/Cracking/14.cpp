#include <iostream>
#include <string>
using namespace std;

#include <string.h>

bool anagram(string s1, string s2)
{
	if(s1.size() != s2.size())
		return false;
	int exist[256];int i;
	memset(exist,0,sizeof(exist));
	for(i=0;i<s1.size();i++) exist[s1.at(i)]++;
	for(i=0;i<s2.size()&&exist[s2.at(i)]>=1;i++) exist[s2.at(i)]--;
	if(i<s2.size()) return false;
	for(i=0;i<256&&exist[i]==0;i++);
	if(i<256) return false;
	return true; 
}

int main()
{
	return 0;
}