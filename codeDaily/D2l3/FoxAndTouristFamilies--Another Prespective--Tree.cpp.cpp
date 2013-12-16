#include <vector>
#include <string>
#include <string.h>
using namespace std;

//can build tree, but difficult.
//like the nearest parent node in the multi-tree
int map[51][51];
vector<int> f;int n;
int dfs(int start,int parent,int through,int a,int b)
{
	int total=(through==1);
	for(int i=0;i<n+1;i++)
	{
		if(map[start][i]==1&&i!=parent)
		{
			int xx=through;
			if(xx==0&&(start==a||start==b)&&(i==a||i==b)) xx=1;
			total+=dfs(i,start,xx,a,b);
		}
	}
	return total;
}
//Another perspective
double expectedLength(vector<int> const &A, vector<int> const &B, vector<int> const &f1) 
{
	memset(map,0,sizeof(map));n=A.size();
	f=vector<int>(f1.begin(),f1.end());int i,j;double rs=0;
	for(i=0;i<n;i++){ map[A.at(i)][B.at(i)]=1;map[B.at(i)][A.at(i)]=1;}
    for(i=0;i<n;i++)
    {
    	double p=1.0;
    	for(j=0;j<f1.size();j++)
    	{
    		double a1=dfs(f1.at(j),-1,0,A.at(i),B.at(i));
    		p*=a1/n;
    	}
    	rs+=p;
    }	
    return rs;
}
