#include <iostream>
#include <string>
using namespace std;

string str[2];
bool flag = false;

int count(string s1, string s2)
{
	unsigned int i=0,j=0;int num=0;
	while(i<s1.size() && j<s2.size())
	{
		if(s1.at(i) != s2.at(j))
			break; 
		num++; i++;j++;
	}
	return num;
}

int main()
{
	int gspace = 0;
	cin>>str[0];cout<<str[0]<<endl;
	flag = true;
	while(cin>>str[flag])
	{
		int same = count(str[flag],str[!flag]);
		if(same <= gspace)
			gspace = same;
		else 
			gspace++;
		printf("%*s\n",gspace+str[flag].size(),str[flag].c_str());
		flag = !flag;
	}

	return 0;
}