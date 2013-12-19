#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

typedef long long int64;

string oldpwd;vector<int>rest;vector<int64> dp[1<<17][17];int n;
int flags[1<<17][17];//-1 not 0 error 1 have

int total=0;
int dfs(int mask,int pos)
{
	int&res=flags[mask][pos];
	if(res==-1)
	{
		res=1;total++;//if(total%10000==0) cout<<total<<endl;
		if(pos==n){dp[mask][pos].push_back(0);}
		else
		{
			int i,j;int64 subpwd=atoll(oldpwd.substr(0,n-pos).c_str());
			vector<int64>&res2=dp[mask][pos];
			FF(i,n)
			{
				if((mask&(1<<i))!=0)
				{
					if(rest.at(n-1-pos)!=oldpwd.at(i)-'0')
					{
						if(dfs(mask^(1<<i),pos+1)==0) continue;
						vector<int64> prev=dp[mask^(1<<i)][pos+1], res3;
						FF(j,prev.size()) res3.push_back(prev.at(j)*10+oldpwd.at(i)-'0');
						if(res3.size()==0) continue;sort(res3.begin(),res3.end());
						int64 mm=abs(res3.at(0)-subpwd);vector<int64> res4,res5;
						FF(j,res2.size()) if(abs(res2.at(j)-subpwd)<mm) mm=abs(res2.at(j)-subpwd);
						FF(j,res3.size()) if(abs(res3.at(j)-subpwd)<mm) mm=abs(res3.at(j)-subpwd);
						FF(j,res2.size()) if(abs(res2.at(j)-subpwd)<=mm+1) res4.push_back(res2.at(j));
						FF(j,res3.size()) if(abs(res3.at(j)-subpwd)<=mm+1) res4.push_back(res3.at(j));
						sort(res4.begin(),res4.end());
						j=0;
						while(j<res4.size())
						{
							res5.push_back(res4.at(j));int k=j;j++;
							while(j<res4.size()&&res4.at(k)==res4.at(j)) j++;
						}
						res2=vector<int64>(res5.begin(),res5.end());
					}
				}
			}
			if(res2.size()==0) res=0;
		}
	}
	return res;
}

int64 newPassword(int64 oldPassword,vector<int> const &restrictedDigits) 
{
	int64 oo=oldPassword;
	while(oldPassword>0){oldpwd.push_back('0'+oldPassword%10);oldPassword/=10;}
	reverse(oldpwd.begin(),oldpwd.end()); n=oldpwd.size();int i;
	FF(i,oldpwd.size()) if(oldpwd.at(i)-'0'==restrictedDigits.at(i)) break;
	if(i==oldpwd.size()) return oo;
	rest=vector<int>(restrictedDigits.begin(),restrictedDigits.end());
	memset(flags,-1,sizeof(flags));if(dfs((1<<n)-1,0)==0) return -1;
	vector<int64>&res2=dp[(1<<n)-1][0];
	if(res2.size()==0) return -1;
	else if(res2.size()==1) return res2.at(0);
	else
	{
		if(res2.at(0)<res2.at(1)) return res2.at(0);
		return res2.at(1);
	}
}

/*int main()
{
	int arr[]={4,7};vector<int> restrictedDigits(arr,arr+sizeof(arr)/sizeof(int));
	cout<<newPassword(58,restrictedDigits)<<endl;
	return 0;
}*/