#include <vector>
#include <string>
#include <set>
using namespace std;

typedef pair<int,int> _pcoor;

#define FF(i,n) for(i=0;i<n;i++)

int minArea(vector<int> const &moves) 
{
	set<_pcoor> _pSet;int n=moves.size();
	_pSet.insert(make_pair(0,0));int i,j;
	vector<int> _ver;int dir=0;_pcoor cur;
	cur=make_pair(0,0);
	//x: min max
	//y: min max
	FF(i,4) _ver.push_back(0);
	
	FF(i,n)
	{
		FF(j,moves.at(i))
		{
			if(dir==0) cur.first+=1;
			else if(dir==1) cur.second+=1;
			else if(dir==2) cur.first-=1;
			else cur.second-=1;
			if(_pSet.find(cur)==_pSet.end()) _pSet.insert(cur);
			else return -1;
		}
		if(dir==0) _ver[1]=max(_ver[1],cur.first);
		else if(dir==1) _ver[3]=max(_ver[3],cur.second);
		else if(dir==2) _ver[0]=min(_ver[0],cur.first);
		else _ver[2]=min(_ver[2],cur.second);

		dir=(dir+1)%4;
	}

	cur=make_pair(0,0);dir=0;
	set<_pcoor> _pSet2;_pSet2.insert(cur);
	FF(i,n)
	{
		int m=moves.at(i);
		FF(j,m)
		{
			if(dir==0) cur.first+=1;
			else if(dir==1) cur.second+=1;
			else if(dir==2) cur.first-=1;
			else cur.second-=1;
			if(_pSet2.find(cur)==_pSet2.end()) _pSet2.insert(cur);
			else return -1;
		}
		if(i==n-1) break;
		if(dir==0)
		{	
			_pcoor cur2=cur;cur2.first++;
			if(cur2.first>_ver[1]||_pSet2.find(cur2)!=_pSet2.end()){}
			else return -1;
		}
		else if(dir==1)
		{
			_pcoor cur2=cur;cur2.second++;
			if(cur2.second>_ver[3]||_pSet2.find(cur2)!=_pSet2.end()){}
			else return -1;
		}
		else if(dir==2)
		{
			_pcoor cur2=cur;cur2.first--;
			if(cur2.first<_ver[0]||_pSet2.find(cur2)!=_pSet2.end()){}
			else return -1;
		}
		else
		{
			_pcoor cur2=cur;cur2.second--;
			if(cur2.second<_ver[2]||_pSet2.find(cur2)!=_pSet2.end()){}
			else return -1;
		}
		dir=(dir+1)%4;
	}

	return (_ver.at(1)-_ver.at(0)+1)*(_ver.at(3)-_ver.at(2)+1);
}