#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <string.h>

#define FF(i,n) for(i=0;i<n;i++)

int main()
{
	int matrix[101][101];int n,A,B,a,b,i,j;memset(matrix,-1,sizeof(matrix));cin>>n>>A>>B;
	FF(i,n){cin>>a;FF(j,a){cin>>b;matrix[i][b-1]=(j==0)?0:1;} } A--;B--;
	FF(i,n)FF(j,n)if(matrix[i][j]==-1){if(i==j) matrix[i][j]=0;else matrix[i][j]=0x3fffff;}
	vector<int>flag(n,0);vector<int>dist(n,0);FF(i,n) if(i!=A) dist[i]=matrix[A][i]; flag[A]=1;
	int id=A;int num=1;int r=0;while(num<n&&id!=B)
	{
		int m=0x3fffff;
		FF(i,n)if(flag.at(i)==0){ if(m>dist[i]) { id=i;m=dist[i]; } }
		if(m==0x3fffff) break; flag[id]=1;
		FF(i,n) if(flag[i]==0 ) dist[i]=min(dist[i],dist[id]+matrix[id][i]);
		num++;
	}
	if(id==B) cout<<dist[B]<<endl;else cout<<-1<<endl;
	return 0;
}