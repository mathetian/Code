#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include <assert.h>

typedef vector<string> SVec;
SVec dicts[30001];

struct cmp
{
	bool operator()(const SVec &s1, const SVec &s2)
	{
		if(s1.size() < s2.size()) return false;
		else if(s1.size() > s2.size()) return true;
		else return s1.at(0) < s2.at(0);
	}
};

int main()
{
	string str, str2;map<string,int>poss;
	int pos = 0;
	while(cin>>str)
	{
		str2 = str;
		sort(str.begin(),str.end());
		if(poss.find(str) == poss.end())
			poss[str] = pos++;
		dicts[poss[str]].push_back(str2);
	}
	for(int i=0;i<pos;i++)
		sort(dicts[i].begin(), dicts[i].end());

	sort(dicts,dicts+pos,cmp());
	for(int i=0;i<min(5,pos);i++)
	{
		cout<<"Group of size "<<dicts[i].size()<<": ";
		for(unsigned int j=0;j<dicts[i].size();j++)
		{
			if(j>0&&dicts[i][j]==dicts[i][j-1])
                continue;
			cout<<dicts[i][j]<<" ";
		}
		cout<<"."<<endl;
	}
	return 0;
}