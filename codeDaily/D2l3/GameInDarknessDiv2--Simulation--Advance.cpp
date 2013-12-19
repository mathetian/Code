#include <vector>
#include <string>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

int xx[]={0,0,-1,1};int yy[]={1,-1,0,0};

void print(vector<vector<int> > fff)
{
	int n=fff.size(),m=fff.at(0).size();int i,j;
	FF(i,n)
	{
		FF(j,m)
			cout<<fff[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

string check(vector<string> const &field, vector<string> const &moves) 
{
	int n=field.size(),m=field.at(0).size();
	int ia,ib;int i,j,k,l;int flag=0;
	FF(i,n)
	{
		FF(j,m)
		{
			if(field.at(i).at(j)=='A')
			{
				flag=1;break;
			} 
		} 
		if(flag==1) break;
	}
	ia=i;ib=j;vector<pair<int,int> > iiVec;
	FF(i,moves.size())
	{
		FF(j,moves.at(i).size())
		{
			if(moves.at(i).at(j)=='U') ia-=1;
			else if(moves.at(i).at(j)=='D') ia+=1;
			else if(moves.at(i).at(j)=='L') ib-=1;
			else ib+=1;
			iiVec.push_back(make_pair(ia,ib));
		}
	}
	vector<vector<int> > fields[2];
	fields[0]=vector<vector<int> >(n,vector<int>(m,0));
	FF(i,n)
	{
		FF(j,m) if(field.at(i).at(j)=='B') { fields[0][i][j]=1;break;}
	}

	FF(i,iiVec.size())
	{
		ia=iiVec.at(i).first;ib=iiVec.at(i).second;
		fields[1]=vector<vector<int> >(n,vector<int>(m,0));
		int num=0;flag=0;
		FF(j,n)
		{
			FF(k,m)
			{
				if(fields[0][j][k]==0) continue;
				if(ia==j&&ib==k) 
				{
					flag=1;
					break;
				}
				FF(l,4)
				{
					int nx=j+xx[l],ny=k+yy[l];
					if(nx<0||ny<0||nx>=n||ny>=m) continue;
					if(field[nx][ny]=='#') continue;
					if(ia==nx&&ib==ny) continue;
					if(i<iiVec.size()-1)
					{
						if(iiVec.at(i+1).first==nx&&iiVec.at(i+1).second==ny) continue;
					}
					fields[1][nx][ny]=1;num=1;
				}
			}
			if(flag==1) break;
		}
		if(num==0||flag==1) return "Alice wins";
		swap(fields[0],fields[1]);
	}
    return "Bob wins";
}
