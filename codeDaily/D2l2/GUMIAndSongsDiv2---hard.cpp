#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

/*typedef struct{
	int a,b;
}E;*/
/*vector<E> eV;

void clear()
{
	int size=eV.size();
	while(size--) eV.pop_back();
}

void dfs(int i,int l,int t,int T,int n,int&N,int o)
{	
	N=max(n,N);

	for(;i<l;i++)
	{
		int a=eV.at(i).a,b=eV.at(i).b;
		int nt=t+a;
		if(t!=0) nt=nt+abs(b-o);
		if(nt>T) continue;
		dfs(i+1,l,nt,T,n+1,N,b);
	}
}

int maxSongs(vector<int> const &duration,
             vector<int> const &tone,
             int T) {
	clear();	
	for(int i=0;i<duration.size();i++)
	{
		E e;e.b=tone.at(i);
		e.a=duration.at(i);
		eV.push_back(e);
	}
	int N=0;
	dfs(0,eV.size(),0,T,0,N,0);
    return N;
}

int main()
{
	int d1[]={383, 85, 353, 664, 603, 681, 600, 485, 263, 467};
	int d2[]={688, 201, 853, 665, 750, 525, 514, 888, 103, 191};
	vector<int>duration(d1,d1+sizeof(d1)/sizeof(int));
	vector<int>tone(d2,d2+sizeof(d1)/sizeof(int));
	cout<<maxSongs(duration,tone,2821)<<endl;
	return 0;
}*/

/*int maxSongs(vector<int> const &duration,
             vector<int> const &tone,
             int T) {
	vector<int> order;int m=0;
	for(int i=0;i<duration.size();i++)	order.push_back(i);
	do{
		int dp=order.at(0);int tp=tone.at(dp);
		int t=duration.at(dp);int n=0;
		if(t<=T) n=1;
		for(int i=1;i<duration.size()&&t<T;i++)
		{
			dp=order.at(i);
			t=t+duration.at(dp)+abs(tone.at(dp)-tp);
			if(t<=T) n++;
		}
		m=max(n,m);
	}while(next_permutation(order.begin(),order.end()));
	return m;
}*/

int maxSongs(vector<int> const &duration,
             vector<int> const &tone,
             int T) {
	int x=1<<duration.size();int m=0;
	for(int i=0;i<x;i++)
	{
		int sum=0;int n=0;vector<int>tones;
		int size=duration.size();
		for(int j=0;j<size;j++)
		{
			if((i&(1<<j))!=0)
			{
				sum+=duration.at(j);n++;
				tones.push_back(tone.at(j));
			}
		}
		if(sum>T) continue;
		sort(tones.begin(),tones.end());
		size=tones.size();
		for(int j=0;j<size-1&&sum<=T;j++) 
			sum+=tones.at(j+1)-tones.at(j);
		if(sum>T) continue;

		m=max(m,n);
	}
	return m;
}

/*int main()
{
	int d1[]={3, 5, 4, 11};
	int d2[]={2, 1, 3, 1};
	vector<int>duration(d1,d1+sizeof(d1)/sizeof(int));
	vector<int>tone(d2,d2+sizeof(d1)/sizeof(int));
	cout<<maxSongs(duration,tone,17)<<endl;
	return 0;
}*/
