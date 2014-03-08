/*#include <iostream>
#include <set>
using namespace std;*/

/**
	Greedy algorithm, Dynamic Programming
**/

/*typedef long long int64;*/

/*int64 dp[50001][50001];*/

/*int main()
{
	int n,m;int i,j,pos;
	while(cin>>n>>m)
	{
		if(n==-1) break;set<int>iset;
		for(i=0;i<n;i++)
		{
			if(i==n-1)
			{
				for(j=1;j<=n;j++) if(iset.find(j)==iset.end()) 
				break; cout<<j<<endl;
			}
			else
			{
				int aaa=0;
				for(j=1;j<=n;j++) 
				{
					if(iset.find(j)==iset.end())
					{
						int num=0;
						set<int>::iterator itset=iset.begin();
						for(;itset!=iset.end();itset++)
							if(*itset<j) num++;
						if(aaa+j-1-num+(n-i-2)*(n-i-3)/2<m) m=m-(aaa+j-1-num+(n-i-2)*(n-i-3)/2);
						else break;
					}
				}
				cout<<j<<" ";iset.insert(j);
			}
		}
	}
	return 0;
}*/

/*#include <stdio.h>
int main(int argc, char *argv[])
{
    int n,m;
    int p,temp,i;
    while(scanf("%d%d",&n,&m) && n>0)
    {
        p=1;
        while((p*(p-1))/2<m)p++;
        temp=(p*(p-1))/2;
        for(i=1;i<=n-p;i++)
            printf("%d ",i);
        printf("%d ",n-temp+m);
        for(i=n;i>=n-p+1;i--)
        {
            if(i!=n-temp+m)
                printf("%d ",i);
        }
        printf("\n");
    }
    return 0;
}*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n,m;int i,j;
	while(cin>>n>>m)
	{
		if(n==m&&n==-1) break;if(m==0)
		{
			for(j=1;j<n;j++) cout<<j<<" ";
			cout<<n<<endl; continue;
		}
		for(i=1;i<=n;i++)
		{
			if(i*(i-1)/2>=m) break;
		}
		vector<int> rs;
		for(j=1;j<=n-i;j++) rs.push_back(j);
		if(i*(i-1)/2==m)
		{
			for(j=n;j>n-i;j--) rs.push_back(j);
		}
		else
		{
			int k=i-1;
			while(k+(i-1)*(i-2)/2!=m)
				k--;
			rs.push_back(k+n-i+1);
			for(j=n;j>n-i;j--)
			{
				if(j!=k+n-i+1)
					rs.push_back(j);
			}
		}
		for(i=0;i<rs.size()-1;i++)
			cout<<rs.at(i)<<" ";
		cout<<rs.at(rs.size()-1)<<endl;
	}
	return 0;
}