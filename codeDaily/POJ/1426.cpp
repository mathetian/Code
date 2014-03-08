#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

/*string dp[300];

string walk(int index)
{
	queue<pair<string,int> >sque;
	sque.push(make_pair("1",1));
	while(!sque.empty())
	{
		string str=sque.front().first;
		int r=sque.front().second;sque.pop();
		if(r==0) return str;
		string str2=str;int nr=(10*r)%index;
		str.push_back('0');str2.push_back('1');
		sque.push(make_pair(str,nr));
		sque.push(make_pair(str2,(nr+1)%index));
	}
	return "";
}

int main()
{
	int i;dp[1]=1;for(i=2;i<=201;i++) 
	dp[i]=walk(i);
	while(cin>>i)
	{
		if(i==0) break;
		if(i==1){cout<<1<<endl;continue;}
		cout<<dp[i]<<endl;
	}
	return 0;
}*/

int main()
{
	int i,j;
	while(cin>>i)
	{
		if(i==0) break;
		if(i==1) {cout<<i<<endl;continue;}
		int arr[524286];
		arr[1]=1;
		for(j=1;;j++)
		{
			arr[2*j]=(arr[j]*10)%i;
			if(arr[2*j]==0) break;
			arr[2*j+1]=(arr[2*j]+1)%i;
			if(arr[2*j+1]==0) break;
			//cout<<j<<endl;
			//cout<<j<<" "<<arr[2*j]<<" "<<arr[2*j+1]<<endl;
		}
		if(arr[2*j]==0) j=2*j;
		else j=2*j+1;
		string rs;
		while(j>0)
		{
			rs.push_back(j%2+'0');
			j/=2;
		}
		reverse(rs.begin(),rs.end());
		cout<<rs<<endl;
	}
}