#include <iostream>
using namespace std;

#include <string.h>

#define FF(i, n) for(i=0;i<n;i++)

pair<int,int> boards[5100];
int count1[5100];

int n,m,x1,y11,x2,y2;

int go1(int a, int b, pair<int,int> line)
{
	pair<int,int> a1 = make_pair(line.first - a,y11-b);
	pair<int,int> a2 = make_pair(line.second - a,y2-b);
	return a1.first*a2.second-a1.second*a2.first;	
}

void process(int a,int b)
{
	int l = 0, r = n + 1;
	while(l < r)
	{
		int m = (l+r)>>1;
		if(go1(a,b,boards[m])>0) l = m;
		else r = m;
	}

	count1[r]++;
}

int main()
{
	while(cin>>n && n!= 0)
	{
		cin>>m>>x1>>y11>>x2>>y2;
		memset(count1, 0, sizeof(count1));
		int i, a, b; FF(i,n)
		{
			cin>>a>>b;
			boards[i] = make_pair(a,b);
		}
		boards[n] = make_pair(x1,x2);
		FF(i,m)
		{
			cin>>a>>b; process(a,b);			
		}
		FF(i,n+1)
		{
			cout<<i<<": "<<count1[i]<<endl;
		}
		cout<<endl;
	}
	return 0;
}