#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include <string.h>

string dfs(vector<int> freq)
{
	string str1; int flag=0;
	for(int i=0;i<36;i++)
	{
		if(freq[i]!=0)
		{
			flag=1;
			if(i<=9) str1.push_back(i+'0');
			else str1.push_back(i-10+'a');
			freq[i]--;
		}
	}
	if(flag==0) return str1;
	str1+=dfs(freq);
	return str1;
}

string convert(string str)
{
	vector<int>freq(36,0);
	for(int i=0;i<str.size();i++)
	{
		if(str.at(i)>='0'&&str.at(i)<='9')
			freq[str.at(i)-'0']++;
		else if(str.at(i)>='a'&&str.at(i)<='z')
			freq[str.at(i)-'a'+10]++;
		else return "";
	}

	vector<int>freq2=freq;
	string str1;
	for(int i=0;i<36;i++)
	{
		if(freq[i]!=0)
		{
			if(i<=9) str1.push_back(i+'0');
			else str1.push_back(i-10+'a');
			freq[i]--;
		}
	}
	str1+=dfs(freq);
	return str1;
}

int main()
{
	string str;
	while(std::getline (std::cin,str))
	{
		string rs=convert(str);
		if(rs.size()==0) cout<<"<invalid input string>"<<endl;
		else cout<<rs<<endl;
	}

	return 0;
}