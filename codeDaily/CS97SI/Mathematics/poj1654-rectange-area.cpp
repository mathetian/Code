#include <iostream>
#include <string>
using namespace std;
//Mathematics
#define FF(i,n) for(i=0;i<n;i++)

typedef long long int64;

void change(char flag,int&x,int&y)
{
	switch(flag)
	{
	case '8':y++;break;
	case '2':y--;break;
	case '6':x++;break;
	case '4':x--;break;
	case '9':x++;y++;break;
	case '7':x--;y++;break;
	case '3':x++;y--;break;
	case '1':x--;y--;break;
	default: break;
	}
}

int cross(int x1,int y1,int x2,int y2)
{
	return x1*y2-x2*y1;
}

int main()
{
	int n,x,y,i;string m;cin>>n;
	while(n--)
	{
		cin>>m;x=y=0;i=0;int64 sum=0;
		if(m.at(0)=='5') cout<<0<<endl;
		else
		{
			change(m.at(0),x,y);
			for(i=1;i<m.size();i++)
			{
				int nx=x,ny=y;
				change(m.at(i),nx,ny);
				sum+=cross(x,y,nx,ny);
				x=nx;y=ny;
			}
			if(sum<0) sum=-sum;
			if(sum%2==0) cout<<sum/2<<endl;
			else cout<<sum/2<<".5"<<endl;
		}
	}
	return 0;
}