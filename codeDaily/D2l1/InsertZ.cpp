#include <vector>
#include <string>
using namespace std;

int flag=0;int l1,l2;

void dfs(string const &init,string const &goal,int p1,int p2)
{
	if(flag==1) return;
	if(p1==l1&&p2==l2) flag=1;
	else if(p1==l1)
	{
		if(goal.at(p2)=='z')
			dfs(init,goal,p1,p2+1);
	}
	else if(p2==l2) return;
	else
	{
		if(goal.at(p2)=='z')
		{
			dfs(init,goal,p1,p2+1);
			if(init.at(p1)=='z')
				dfs(init,goal,p1+1,p2+1);
		}
		else
		{
			if(init.at(p1)==goal.at(p2))
				dfs(init,goal,p1+1,p2+1);
		}
	}
}

string canTransform(string const &init,
                    string const &goal) {
	l1=init.size();l2=goal.size();
	if(l1>l2) return "No";
	else if(l1==l2)
	{
		if(init==goal)return "Yes";
		return "No";
	}
	flag=0;
	dfs(init,goal,0,0);
	if(flag==1) return "Yes";
	return "No";
}