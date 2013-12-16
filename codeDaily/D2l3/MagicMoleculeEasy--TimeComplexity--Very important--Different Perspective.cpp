#include <vector>
#include <string>
using namespace std;

//different perspective
#define FF(i,n) for(i=0;i<n;i++)

//complexity??
vector<pair<int,int> > edges;int mx=-1;
vector<int> flags;vector<int> power;int k,n;

/*void dfs(int edNum,int a,int d)
{
	if(edNum==edges.size())
	{
		vector<int> va;
		for(int i=0;i<n;i++) if(flags.at(i)==0) va.push_back(power.at(i));
		sort(va.begin(),va.end());
		for(int i=0;i<k-d;i++) a+=va.at(va.size()-1-i);
		mx=max(mx,a);
	}
	else if(d>k) return;
	else if(d==k)
	{
		for(int a1=edNum;a1<edges.size();a1++)
		{
			int b=edges.at(a1).first,c=edges.at(a1).second;
			if(flags.at(b)==0&&flags.at(c)==0) return;
		}
		mx=max(mx,a);
	}
	else
	{
		int b=edges.at(edNum).first,c=edges.at(edNum).second;
		if(flags.at(b)==1&&flags.at(c)==1) dfs(edNum+1,a,d);
		else
		{
			if(flags.at(b)==1)
			{
				flags[c]=1;dfs(edNum+1,a+power.at(c),d+1);
				flags[c]=0;dfs(edNum+1,a,d);
			}
			else if(flags.at(c)==1)
			{
				flags[b]=1;dfs(edNum+1,a+power.at(b),d+1);
				flags[b]=0;dfs(edNum+1,a,d);
			}
			else
			{
				flags[b]=1;flags[c]=1;
				dfs(edNum+1,a+power.at(b)+power.at(c),d+2);
				flags[b]=1;flags[c]=0;
				dfs(edNum+1,a+power.at(b),d+1);
				flags[b]=0;flags[c]=1;
				dfs(edNum+1,a+power.at(c),d+1);
				flags[b]=0;flags[c]=0;
			}
		}
	}
}*/

/*I can understand it will cost much time for my implementation. However, how to compare with them directly.
*/
#define FF(i,n) for(i=0;i<n;i++)

void dfs(int edNum,int a,int d)
{
	if(edNum==edges.size())
	{
		vector<int> va;int i;
		FF(i,n) if(flags.at(i)==0) va.push_back(power.at(i));
		sort(va.begin(),va.end());
		FF(i,k-d) a+=va.at(va.size()-1-i);
		mx=max(mx,a);
	}
	else if(d>k) return;
	else if(d==k)
	{
		for(int a1=edNum;a1<edges.size();a1++)
		{
			int b=edges.at(a1).first,c=edges.at(a1).second;
			if(flags.at(b)==0&&flags.at(c)==0) return;
		}
		mx=max(mx,a);
	}
	else
	{
		int b=edges.at(edNum).first,c=edges.at(edNum).second;
		if(flags.at(b)==1||flags.at(c)==1) dfs(edNum+1,a,d);
		else
		{
			flags[b]=1;dfs(edNum+1,a+power.at(b),d+1);flags[b]=0;
			flags[c]=1;dfs(edNum+1,a+power.at(c),d+1);flags[c]=0;
		}
	}
}

int maxMagicPower(vector<int> const &magicPower, vector<string> const &magicBond, int k1) 
{
	n=magicBond.size();int i,j;power=vector<int>(magicPower.begin(),magicPower.end());
	FF(i,n) FF(j,i) if(magicBond[i][j]=='Y') edges.push_back(make_pair(i,j));k=k1;
	flags=vector<int>(n,0);dfs(0,0,0);return mx;
}