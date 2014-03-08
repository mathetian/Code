#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n,i1,i2;string a,b,c;
	int i,j,remain;cin>>n;while(n--)
	{
		cin>>a>>b;i1=a.size();c.clear();
		i2=b.size();remain=i=j=0;
		while(i<i1&&j<i2)
		{
			remain+=a.at(i)+b.at(j)-2*'0';
			c.push_back(remain%10+'0');
			remain/=10;i++;j++;
		}
		while(i<i1) 
		{
			remain+=a.at(i)-'0';
			c.push_back(remain%10+'0');
			remain/=10;i++;
		}
		while(j<i2)
		{
			remain+=b.at(j)-'0';
			c.push_back(remain%10+'0');
			remain/=10;j++;
		}
		if(remain!=0) c.push_back(remain+'0');
		j=0;while(j<c.size()&&c.at(j)=='0') j++;
		cout<<c.substr(j)<<endl;
	}
	return 0;
}