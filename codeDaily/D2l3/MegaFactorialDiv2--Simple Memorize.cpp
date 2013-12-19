#include <vector>
#include <string>
#include <string.h>
#include <map>
#include <iostream>
using namespace std;

#define MX 1000000009

/*map<int,int> iiM;

map<int,int> values[1000][100];
int flags[1001][101];

void divide(int n,int k)
{
	if(flags[n][k]==1)
	{
		map<int,int>::iterator mIt=values[n][k].begins();
		while(mIt!=values[n][k].end())
		{
			mIt->second*=2;mIt++;
		}
	}
	else if(n==0){}
	else if(k==0)
	{
		if(values[n].size()!=0)
		{
			map<int,int>::iterator mIt=values[n][0].begins();
			while(mIt!=values[n][0].end())
			{
				mIt->second*=2;mIt++;
			}
		}
		else
		{
			int i=2;
			while(i<=n)
			{
				int t=0;
				while(n%i==0)
				{
					n=n/i;t++;
				}
				if(t!=0) values[n][0].insert(make_pair(i,t));
				i++;
			}
		}
	}
	else
	{
		divide(n,k-1);divide(n-1,k);
		values[n][k]=map<int,int>(values[n][k-1].begin(),values[n][k-1].end());
		map<int,int>::iterator mIt=values[n-1][k].begin();
		while(mIt!=values[n-1][k].end())
		{
			if(values[n][k].find(mIt->first)==values[n][k].end()) values[n][k].insert(*mIt);
			else values[n][k][mIt->first]+=mIt->second;mIt++;
		}
	}
	flags[n][k]=1;
}

int countDivisors(int N, int K) 
{
    memset(flags,0,sizeof(flags));divide(N,K);
    map<int,int>::iterator mIt=values[N][K].begin();
    int64 rs=1;
    while(mIt!=values[N][K].end())
    {
    	rs*=(mIt->second+1);rs%=MX;
    	mIt++;
    }
    return rs;
}*/

typedef long long _int64;

int flags[1001][101];

map<int,_int64> iims[1001][101];

void get(int n,int k)
{
	if(flags[n][k]!=0||n==0) return;
	//cout<<"("<<n<<" "<<k<<")"<<endl;
	map<int,_int64>&iim=iims[n][k];
	flags[n][k]=1;
	if(k==0)
	{
		if(n==1) return;int i=2;int t=0;
		while(i<=n)
		{
			t=0;while(n%i==0&&++t) n/=i;
			if(t!=0) iim.insert(make_pair(i,t));
			i++;
		}
	}
	else
	{
		get(n-1,k);get(n,k-1);
		map<int,_int64>&i1=iims[n-1][k],&i2=iims[n][k-1];
		iim=map<int,_int64>(i1.begin(),i1.end());
		map<int,_int64>::iterator it=i2.begin();
		while(it!=i2.end())
		{
			if(iim.find(it->first)!=iim.end())
				iim[it->first]+=it->second;
			else iim.insert(*it);
			iim[it->first]%=MX;
			it++;
			
		}
	}
}

int countDivisors(int N, int K) 
{
	memset(flags,0,sizeof(flags));
	get(N,K);_int64 a=1;map<int,_int64>&iim=iims[N][K];
	map<int,_int64>::iterator it=iim.begin();
	while(it!=iim.end())
	{
		a=(a*(it->second+1))%MX;it++;
	}
	return a;
}

/*int main()
{
	cout<<countDivisors(77,11)<<endl;
}*/