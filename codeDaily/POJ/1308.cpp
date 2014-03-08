#include <map>
#include <set>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int a,b; int case1 = 1;
	while(cin>>a>>b)
	{
		if(a==-1&&b==-1) break;
		map<int,vector<int> > maps;
		set<int> iset;
		int flag=1; int num=0;
		while(a!=0&&b!=0)
		{
			if(maps.find(b) == maps.end())
			{
				maps[b].push_back(a); num++;
			}	
			else
				maps[b].push_back(a);

			if(a == b) flag = 0;
			iset.insert(a);iset.insert(b);
			cin>>a>>b;
		}

		if(iset.size() == 0)
			flag = 1;
		else if(num != iset.size() - 1)
			flag=0;
		else
		{
			map<int, vector<int> >::iterator iter = maps.begin();
			for(;iter != maps.end();iter++)
			{
				if((*iter).second.size() >=2)
					flag = 0;
			}
		}
		if(flag == 0)
			cout<<"Case "<<case1<<" is not a tree."<<endl;
		else
			cout<<"Case "<<case1<<" is a tree."<<endl;
		case1++;

	}
	return 0;
}