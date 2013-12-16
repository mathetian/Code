#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

string convert(int A)
{
	string str;
	while(A!=0)
	{
		str.push_back(A%10+'0');
		A=A/10;
	}
	reverse(str.begin(),str.end());
	return str;
}

int minimumMoves(int A,
                 int B) {
    
	vector<string> _strVec;
	string a=convert(A),b=convert(B);int t=0;
	queue<pair<string,int> >strQue;
	strQue.push(make_pair(a,0));
	set<string>used;used.insert(a);
	while(!strQue.empty())
	{
		a=strQue.front().first;
		t=strQue.front().second;
		strQue.pop();string old=a;
		if(b==a) return t;

		if(old.at(old.size()-1)!='0')
		{
			reverse(old.begin(),old.end());
			if(used.find(old)==used.end())
			{
				used.insert(old);
				strQue.push(make_pair(old,t+1));
			} 
		}
		
		if(a.size()>=2)
		{
			a=a.substr(0,a.size()-1);
			if(used.find(a)==used.end())
			{
				used.insert(a);
				strQue.push(make_pair(a,t+1));
			}
		}
	}
    return -1;
}
