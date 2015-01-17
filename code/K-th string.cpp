#include <iostream>
using namespace std;

#include <stdint.h>
uint64_t arr[100][100];

void precompute()
{
	for(int i=1;i<70;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0||j==i) arr[i][j]=1;
			else
				arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
		}
	}
}

int main()
{
	precompute(); int c;cin>>c;
	while(c--)
	{
		uint64_t n,m,k; cin>>n>>m>>k;
		string str;int r=m;
		if(k>arr[n+m][m])
		{
			cout<<"Impossible"<<endl;
			continue;
		}
		for(int i=0;i<n+m;i++)
		{
			if(k>arr[n+m-i-1][r]&&r>0)
			{
				k-=arr[n+m-i-1][r];r--;
				str.push_back('1');
			} 
			else
			{
				str.push_back('0');
			} 
		}
		cout<<str<<endl;
	}
	return 0;
}