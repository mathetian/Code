#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

int main()
{
	int n,i,j,k,m,a,b;while(cin>>n && n!=0)
	{
		vector<vector<int> >matrix(n,vector<int>(n,0));
		FF(i,n){cin>>m;FF(j,m){ cin>>a>>b; matrix[i][a-1]=b; }}
		FF(i,n) FF(j,n) if(matrix[i][j]==0 && i!=j) matrix[i][j]=0x3fffff;
		FF(k,n)FF(i,n)FF(j,n)
		{
			matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
		}

		int r1 = 0, r2 =0x3fffff;
		FF(i,n)
		{
			int tmp = 0;FF(j,n) tmp=max(tmp,matrix[i][j]);
			if(tmp < r2)
			{
				r2=tmp;r1=i;
			}
		}
		if(r2==0x3fffff) cout<<"disjoint"<<endl;
		else
		{
			cout<<r1+1<<" "<<r2<<endl;
		}
	}
	return 0;
}