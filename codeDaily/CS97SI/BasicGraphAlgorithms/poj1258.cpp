#include <iostream>
#include <vector>
<<<<<<< HEAD
#include <set>
using namespace std;

#define FF(i,n) for(i = 0;i < n;i++)
#define FS(i,a,b) for(i = a;i < b;i++)

int main()
{
	int n; int i, j;
	while(cin>>n)
	{
		if(n == 0) break;
		vector<vector<int> > matrix(n,vector<int>(n,0));
		/**
			Can't write any code. Bad feeling.
		**/
		FF(i, n) FF(j, n) cin >> matrix[i][j];
		set<int>S; set<int>Q;
		
		FS(i,1,n) 
		{

		}

	}
	return 0;
}
=======
#include <queue>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)
#define FS(i,a,b) for(i=a;i<b;i++)

typedef struct _tEdge{
	int a,b; int length;
	_tEdge(int x,int y,int z)
	{ a=x;b=y;length=z; }
}Edge;

struct cmp
{
	bool operator()(Edge ea,Edge eb){
	    if(ea.length >= eb.length)
	            return true;
	   	else return false;
	}
};

int parent[101];

int findParent(int a)
{
	while(parent[a]!=a)  a=parent[a];
	return a;
}

bool unionParent(int a,int b)
{
	int a1=findParent(a);
	int a2=findParent(b);
	if(a1==a2) return false;
	parent[a1]=a2; 
	return true;
}

int main()
{
	int n,i,j;while(cin>>n && n != 0)
	{
		priority_queue<Edge,vector<Edge>,cmp>q;
		vector<vector<int> > matrix = vector<vector<int> >\
		(n,vector<int>(n,0));FF(i,n)FF(j,n)cin>>matrix[i][j];FF(i,n)FS(j,i,n)
		if(matrix[i][j]!=0) {Edge edge(i,j,matrix[i][j]); q.push(edge);}
		FF(i,n) parent[i]=i;
		int num=0,sum=0; while(num!=n-1&&!q.empty())
		{
			Edge edge=q.top();q.pop();
			if(unionParent(edge.a,edge.b)==true)
			{	num++;sum+=edge.length;}
		}
		cout<<sum<<endl;
	}
	return 0;
}
>>>>>>> ec46d54ab8ee29e4291e5b7a21b8805d157d49c9
