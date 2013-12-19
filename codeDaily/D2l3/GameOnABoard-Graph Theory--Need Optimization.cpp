#include <vector>
#include <string>
#include <queue>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

int xx[]={0,0,1,-1};int yy[]={1,-1,0,0};
vector<vector<int> > flags;
typedef struct{ int x, y, step; }ELEM;
vector<string> cost;
int n,m;

/*void visitZero(int x,int y,int s,queue<ELEM>&iiQ)
{
	for(int k=0;k<4;k++)
	{
		int nx=x+xx[k], ny=y+yy[k];
		if(nx<0||ny<0||nx>=n||ny>=m) continue;
		if(flags[nx][ny]==1) continue;
		if(cost[nx][ny]=='0')
		{
			 flags[nx][ny]=1;ELEM elem2;elem2.x=nx;
			 elem2.y=ny;elem2.step=s;
			 iiQ.push(elem2);visitZero(nx,ny,s,iiQ);
		}
	}
}*/

int optimalChoice(vector<string> const &costs) 
{
	cost=costs;n=cost.size();m=cost.at(0).size();
	ELEM elem2;int i,j;int mx=0x3fffff;
	FF(i,n)
	{
		FF(j,m)
		{
			flags=vector<vector<int> >(n,vector<int>(m,0));
			flags[i][j]=1;ELEM elem;elem.x=i;elem.y=j;
			elem.step=1;queue<ELEM>iiQ;iiQ.push(elem);
			int mx2=0;
			while(!iiQ.empty())
			{
				elem=iiQ.front();iiQ.pop();
				/*for(int k=0;k<4;k++)
				{
					int nx=cx+xx[k], ny=cy+yy[k];
					if(nx<0||ny<0||nx>=n||ny>=m) continue;
					if(flags[nx][ny]==1) continue;
					if(cost[nx][ny]=='0')
					{
						 flags[nx][ny]=1;elem2.x=nx;elem2.y=ny;
						 elem2.step=elem.step;iiQ.push(elem2);
						 visitZero(nx,ny,elem.step,iiQ);
					}
				}*/
				for(int k=0;k<4;k++)
				{
					int nx=elem.x+xx[k], ny=elem.y+yy[k];
					if(nx<0||ny<0||nx>=n||ny>=m) continue;
					int val=cost[nx][ny]-'0';
					if(flags[nx][ny]!=0&&flags[nx][ny]<=elem.step+val) continue;
					flags[nx][ny]=elem.step+val;elem2.x=nx;
					elem2.y=ny;elem2.step=elem.step+val;
					iiQ.push(elem2);
				}
			}
			for(int k=0;k<n;k++)
			{
				for(int l=0;l<m;l++) mx2=max(mx2,flags[k][l]);
			}

			int val2=cost[i][j]-'0';if(val2==1) val2=0; else val2=1;
	     //   cout<<"i:"<<i<<" "<<"j:"<<j<<" mx2:"<<mx2-val2<<endl;
			mx=min(mx,mx2-val2);
		}
	}
    return mx;
}