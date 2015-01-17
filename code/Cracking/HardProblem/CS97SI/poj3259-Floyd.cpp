#include <iostream>
#include <algorithm>
using namespace std;

#define FF(i,n) for(i = 0;i < n;i++)

int arr[501][501];
int N,M,W;
// typedef struct _tEdge{
// 	int from, to, length;
// 	_tEdge(int a,int b,int c)
// 	{
// 		from = a; to = b; length = c;
// 	}
// }Edge;

// int N,M,W;

// vector<Edge> edges;

void Bellman_ford()
{

}

// int main()
// {
// 	int F; cin>>F;
// 	while(F--)
// 	{
// 		cin>>N>>M>>W;
// 		int i;int a,b,c;
// 		FF(i, M)
// 		{
// 			cin>>a>>b>>c;
// 			a--;b--;
// 			edges.push_back(Edge(a,b,c));
// 			edges.push_back(Edge(b,a,c));
// 		}
// 		FF(i, W)
// 		{
// 			cin>>a>>b>>c;
// 			a--;b--;
// 			edges.push_back(Edge(a,b,-c));
// 		}

// 		Bellman_ford();
// 	}
// 	return 0;
// }

void Floyd()
{
	int i,j,k;
	FF(i,N) FF(j,N) FF(k,N)
	{
		arr[j][k]=min(arr[j][k],arr[j][i]+arr[i][k]);
	}
	FF(i,N) if(arr[i][i] < 0 )
	{
		cout<<"YES"<<endl;
		return;
	}
	cout<<"NO"<<endl;
}

int main()
{
	int F; cin>>F;
	while(F--)
	{
		cin>>N>>M>>W;
		int i,j,a,b,c;
		FF(i,N) FF(j,N)
		{
			if(i == j) arr[i][i] = 0;
			else arr[i][j] = 0x3ffffff;
		}

		FF(i, M)
		{
			cin>>a>>b>>c;
			arr[a-1][b-1]=c;
			//arr[b-1][a-1]=c;
		}

		FF(i,W)
		{
			cin>>a>>b>>c;
			arr[a-1][b-1]=-c;
		}

		Floyd();
	}
}