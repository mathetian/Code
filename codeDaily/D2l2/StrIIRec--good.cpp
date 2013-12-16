#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

/*int getR(string str)
{
	int n=str.size();int cnt=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(str.at(i)<str.at(j)) cnt++;
		}
	}
	return cnt;
}

bool isless(string is,string ir)
{
	int n=is.size();int m=ir.size();
	int i=0,j=0;
	while(i<n&&j<m)
	{
		if(is.at(i)<ir.at(j)) return true;
		else if(is.at(i)>ir.at(j)) return false;
		i++;j++;
	}
	if(i<n) return  false;
	return true;
}

string recovstr(int n, int minInv, string const &minStr) 
{
	string ir;string is;int i,j;int m=minStr.size();
	FF(i,m) is.push_back(n-1-minStr.at(i)+'a'+'a');
	FF(i,n) ir.push_back(i+'a');
	string ttt="";
	do{
		bool flag=isless(is,ir);
		if(isless(ir,is)==false) break;
		int r1=getR(ir);
		if(r1>=minInv) ttt=ir;
	}while(next_permutation(ir.begin(),ir.end()));
    FF(i,n) ttt[i]='a'+'a'+n-1-ttt[i];
    return ttt;
}*/

#define RFF(i,n) for(i=n-1;i>=0;i--)

string recovstr(int n, int minInv, string const &minStr) 
{
	string rs;int i,j,k,l;
	int flag=0;
	FF(i,n)
	{
		FF(j,n)
		{
			int oflag=flag;
			if((oflag&(1<<j))!=0) continue;
			string tmp=rs;tmp.push_back(j+'a');oflag|=(1<<j);
			RFF(k,n) if((oflag&(1<<k))==0) tmp.push_back(k+'a');
			if(tmp<minStr) continue;int num=0;		
			FF(k,n)
			{
				for(l=k+1;l<n;l++) 
					if(tmp.at(k)>tmp.at(l)) num++; 
			}
			if(num<minInv) continue;
			rs.push_back(j+'a');flag|=(1<<j);
			break;
		}
	}
	return rs;
}	