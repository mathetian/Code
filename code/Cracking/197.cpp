#include <iostream>
#include <vector>
using namespace std;

int mxcosum(int*arr,int n)
{
	int rs=0;int mx=0;
	for(int i=0;i<n;i++)
	{
		rs+=arr[i];
		if(rs<0)rs=0;
		mx=max(mx,rs);
	}

	if(mx==0)
	{
		for(int i=0;i<n;i++)
			mx=max(mx,-arr[i]);
	}
	mx=-mx;
	return mx;
}

int main()
{
	return 0;
}