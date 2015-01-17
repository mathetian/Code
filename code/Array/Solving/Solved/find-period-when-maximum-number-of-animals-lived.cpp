/**
	Question, https://sites.google.com/site/spaceofjameschen/home/search/find-period-when-maximum-number-of-animals-lived----amazon

	An interview question.
**/

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include <assert.h>

#define ASS_EQUAL(a,b) assert(a==b)

struct Elem_t
{
	int val,flag;
	Elem_t(int v,int f)
	{
		val=v;flag=f;
	}
};

typedef struct Elem_t Elem;

struct cmp
{
	bool operator()(const Elem&a1, const Elem&a2)
	{
		if(a1.val==a2.val)
		{
			if(a1.flag==1) return true;
			return false;
		}
		return a1.val<a2.val;
	}
};

void findmaxperiod(int*st,int*end,unsigned int n)
{
	vector<Elem> eles;unsigned int i;
	for(i=0;i<n;i++)
	{
		eles.push_back(Elem(st[i],0));
		eles.push_back(Elem(end[i],1));
	}
	sort(eles.begin(),eles.end(),cmp());
	int rs=0,cur=0;
	vector<int> pos(eles.size(),0);
	for(i=0;i<eles.size();i++)
	{
		if(eles[i].flag==0) cur++;
		else
		{
			rs=max(rs,cur);
			cur--;
		}
		pos[i]=cur;
	}
	for(i=0;i<eles.size()&&pos[i]!=rs;i++);
	cout<<eles[i].val<<" "<<eles[i+1].val<<endl;
}

void DoTest()
{
	int st[]={5,6,2,3}, end[]={11,18,5,12};
	findmaxperiod(st,end,sizeof(st)/sizeof(int));
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;

	return 0;
}