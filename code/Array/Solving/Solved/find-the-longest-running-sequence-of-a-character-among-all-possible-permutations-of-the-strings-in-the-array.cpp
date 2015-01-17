/**
	Question, https://sites.google.com/site/spaceofjameschen/home/string/find-the-longest-running-sequence-of-a-character-among-all-possible-permutations-of-the-strings-in-the-array

	Can't understand.
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

char t;int freq;
void permuate(const vector<string> &strs, const string &rs)
{
	int n=strs.size();
	if(n==0)
	{
		int tfreq=0;char tc;int i=0;
		while(i<rs.size())
		{
			int j=i+1;
			while(j<rs.size()&&rs.at(j)==rs.at(i)) j++;
			if(tfreq<j-i) 
			{
				tfreq=j-i;tc=rs.at(i);
			}
			i=j;
		}
		if(freq<tfreq) 
		{
			freq=tfreq;t=tc;
		}
	}

	for(int i=0;i<n;i++)
	{
		vector<string> vec;
		for(int j=0;j<i;j++) vec.push_back(strs.at(j));
		for(int j=i+1;j<n;j++) vec.push_back(strs.at(j));
		permuate(vec, rs+strs.at(i));
	}
}

void findlongest(const vector<string> &strs)
{
	freq=0;permuate(strs,"");
	cout<<t<<" "<<freq<<endl;
}

void DoTest()
{
	vector<string> strs;
	strs.push_back("ab");
	strs.push_back("ba");
	strs.push_back("aac");

	findlongest(strs);
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;
	
	return 0;
}
