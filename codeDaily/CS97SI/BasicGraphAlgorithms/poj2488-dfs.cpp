#include <iostream>
#include <string>
using namespace std;

#include <string.h>

#define FF(i,n) for(i=0;i<n;i++)
char matrix[27][27];int n,p,q;

int dx[]={-2,-2,-1,-1,+1,+1,+2,+2};
int dy[]={-1,+1,-2,+2,-2,+2,-1,+1};

bool dfs(int x,int y,string&str)
{
	//cout << x <<" "<<y<<" "<<str<<endl;
	int i;FF(i,8)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0||ny<0||nx>=p||ny>=q) continue;
		if(matrix[nx][ny]!=0) continue;
		str.push_back(nx+'A');str.push_back(ny+'1');
		matrix[nx][ny]=1;
		if(dfs(nx,ny,str)==1) return true;
		matrix[nx][ny]=0;
		str=str.substr(0,str.size()-2);
	}
	return str.size()==2*p*q ? true:false;
}

int main()
{
	int i,j;cin>>n; int index=1;
	while(n--)
	{
		cin>>q>>p;
		memset(matrix,0,sizeof(matrix));int flag=1;
		for(i=0;i<p&&flag==1;i++)
		for(j=0;j<q&&flag==1;j++)
		{
			string str;str.push_back(i+'A');
			str.push_back(j+'1');matrix[i][j]=1;
			if(dfs(i,j,str)==1)
			{
				cout<<"Scenario #"<<index<<":\n"<<str<<endl; flag=0;break;
			}
			matrix[i][j]=0;
		}
		if(flag==1) cout<<"Scenario #"<<index<<":\nimpossible"<<endl;
		if(n!=0)cout<<endl;
		index++;
	}
	return 0;
}