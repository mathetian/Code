
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;


string get_next(string origin)
{
	string result;
	result.clear();
	int freq[10];
	for(int i=0;i<10;i++)
		freq[i]=0;
	for(int i=0;i<origin.size();i++)
	{
		freq[origin[i]-'0']++;
	}
	for(int i=0;i<10;i++)
	{
		string tmp2;tmp2.clear();int t=freq[i];
		while(t!=0)
		{
			tmp2.push_back('0'+t%10);t/=10;
		}
		reverse(tmp2.begin(),tmp2.end());
		result.append(tmp2);
		if(freq[i]!=0)
		{
			result.push_back('0'+i);
		}
	}
	return result;
}

int main()
{
	string input;vector<string>sVec;
	while(cin>>input&&input[0]!='-')
	{
		sVec.clear();
		sVec.push_back(input);
		string next2;int steps=0;
		while((next2=get_next(input))!=input&&steps<15)
		{
			steps++;
			int size2=sVec.size();
			for(int i=size2-1;i>=0;i--)
			{
				if(next2==sVec.at(i))
				{
					cout<<sVec.at(0)<<" enters an inventory loop of length "<<size2-i<<"\n";
					goto label1;
				}
			}
			input=next2;
			sVec.push_back(input);
		}
		if(steps==15)
		{
			if(input==get_next(input))
			{
				cout<<sVec.at(0)<<" is self-inventorying after "<<steps<<" steps\n";
			}
			else
				cout<<sVec.at(0)<<" can not be classified after 15 iterations\n";
		}
		else if(steps>=1)
		{
			cout<<sVec.at(0)<<" is self-inventorying after "<<steps<<" steps\n";
		}
		else if(steps==0)
		{
			cout<<sVec.at(0)<<" is self-inventorying\n";
		}
	label1:;
	}
	return 0;
}