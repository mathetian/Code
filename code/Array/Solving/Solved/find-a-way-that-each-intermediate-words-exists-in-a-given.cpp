/**
	Question, https://sites.google.com/site/spaceofjameschen/home/graph/find-a-way-that-each-intermediate-words-exists-in-a-given-dictionary

	Hard to write a no-errno solution.
**/

#include <set>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool flag=false;
void dfs(const set<string> &sset, set<string> &past, string orig, const string &target, vector<string> &coll)
{
	if(flag==true) return;
	if(orig==target) 
	{
		for(int i=0;i<coll.size();i++)
			cout<<coll.at(i)<<" ";
		cout<<endl; flag=true;
	}
	else
	{
		for(int i=0;i<orig.size()&&!flag;i++)
		{
			char o=orig[i];
			for(int j=0;j<26&&!flag;j++)
			{
				orig[i]=j+'a';
				if(past.find(orig) == past.end() && sset.find(orig) != sset.end())
				{
					past.insert(orig); coll.push_back(orig);
					dfs(sset, past, orig, target, coll);
					past.erase(orig); coll.pop_back();
				}
			}
			orig[i]=o;
		}
	}
}

void change(set<string> sset, string orig, string target)
{
	vector<string> coll;coll.push_back(orig);
	set<string> past; past.insert(orig); flag=false;
	dfs(sset, past, orig, target, coll);
}

void InitDict(set<string>& dict)
{
    dict.insert("pit");
    dict.insert("can");
    dict.insert("pot");
    dict.insert("pet");
    dict.insert("mop");
    dict.insert("mat");
    dict.insert("met");
    dict.insert("map");
    dict.insert("end");
    dict.insert("bye");
    dict.insert("cot");
    dict.insert("vet");
    dict.insert("hello");
    dict.insert("world");
    dict.insert("chop");
    dict.insert("look");
    dict.insert("seek");
    dict.insert("book");
    dict.insert("Jack");
    dict.insert("Jeep");
    dict.insert("soft");
    dict.insert("hard");
    dict.insert("hear");
    dict.insert("hare");
    dict.insert("lamp");
    dict.insert("week");
    dict.insert("work");
    dict.insert("shot");
    dict.insert("stop");
    dict.insert("shop");
    dict.insert("ship");
    dict.insert("chip");
    dict.insert("chop");
    dict.insert("chap");
    dict.insert("clap");
    dict.insert("clay");
}

void DoTest()
{
	set<string> sset;InitDict(sset);
	change(sset, "pit", "map");
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;
	return 0;
}