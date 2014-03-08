#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <stdio.h>
#include <math.h>

#define FF(i,n) for(i=0;i<n;i++)

double arr[250][250];

double Bellman(int n)
{
	vector<double>d(n,0);
	
	int i,j,k;
	FF(i,n) d[i]=arr[0][i];

	FF(k,n)
	{
		FF(i,n) FF(j,n)
		{
			if(i==j) continue;

			double tmp = max(d[i],arr[i][j]);
			if(tmp < d[j])
			{
				d[j]=tmp;
			}
		}
	}
	return d.at(1);
}

int main()
{
	int n,i,j;int a,b;int index=1;
	while(cin>>n && n!=0)
	{
		vector<pair<int,int> >points;
		FF(i,n)
		{
			cin>>a>>b;
			points.push_back(make_pair(a,b));
		}

		FF(i,n)
		{
			FF(j,n)
			{
				double a1=points[i].first-points[j].first;
				double a2=points[i].second-points[j].second;
				arr[i][j]=sqrt(a1*a1+a2*a2);
			}
		}
		double rs = Bellman(n);
		cout<<"Scenario #"<<index++<<endl;
		cout<<"Frog Distance = ";
		printf("%0.3f\n\n",rs);
	}
	return 0;
}