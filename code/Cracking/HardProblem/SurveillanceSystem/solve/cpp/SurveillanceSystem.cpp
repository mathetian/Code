#include <vector>
#include <string>
#include <iostream>
using namespace std;

int n;vector<int>flag;int tim;
string containers;int L;
vector<int>reports;vector<int>reUsed;

#define EM 0
#define OCC 1
#define WAIT 2

void dfs(int used, int index,vector<int>&occ,int L)
{
	int i,j;
	if(used==reports.size())
	{
	//	print(occ);
		if(tim==0){ flag=occ;tim=1;}
		else
		{
			for(i=0;i<n;i++)
			{
				if(occ.at(i)==1)
				{
					if(flag.at(i)==OCC){}
					else if(flag.at(i)==EM) flag[i]=WAIT;
				}
				else
				{
					if(flag.at(i)==OCC) flag[i]=WAIT;
				}
			}
		}
	}
	else if(index>n-L) return;
	else
	{
		//without
		dfs(used,index+1,occ,L);
		//with
		int tmp=0;
		for(i=0;i<L;i++)
		{
			if(containers.at(i+index)=='X') tmp++;
		}
		for(i=0;i<reports.size();i++)
		{
			if(reUsed.at(i)==0&&reports.at(i)==tmp) break;
		}
		if(i==reports.size()) return;

		reUsed[i]=1;int j=i;
		for(i=0;i<L;i++) occ[index+i]=1;
		dfs(used+1,index+1,occ,L);
		for(i=0;i<L;i++) occ[index+i]=0;
		reUsed[j]=0;
	}
}


string getContainerInfo(string const &con, vector<int> const &reports1, int L1) 
{
	containers=con;L=L1;reports=reports1;
	reUsed=vector<int>(reports.size(),0);string rs;
	n=containers.size();int i;vector<int> occ(n,0);
	flag=vector<int>(n,0);tim=0;dfs(0,0,occ,L);
	for(i=0;i<n;i++)
	{
		if(flag.at(i)==OCC) rs.push_back('+');
		else if(flag.at(i)==WAIT) rs.push_back('?');
		else rs.push_back('-');
	}
    return rs;
}

/*int main()
{
	string con="-XXXXX-";vector<int>reports1;reports1.push_back(2);int L1=3;
	cout<<getContainerInfo(con,reports1,L1)<<endl;
	return 0;
}*/