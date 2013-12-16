#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

/*int minLevel(vector<int> const &heights) 
{
	int n=heights.size();int i,j;int m1=0;
	FF(i,n-1)
	{
		if(heights.at(i)>heights.at(i+1)) m1=max(heights.at(i)-heights.at(i+1),m1);
	}
	m1=m1/2;

	for(i=m1;i<1000000000;i++)
	{
		int prev=1;
		if(heights.at(0)>=i+1) prev=heights.at(0)-i;
		for(j=1;j<n;j++)
		{
			int h=heights.at(j);
			int l=h-i;
			if(prev>=h)
			{
				l=heights.at(j);
				h=heights.at(j)+i;
				if(prev>=h) break;
				else if(prev<l) prev=l;
				else prev=prev+1;
			}
			else if(prev<l) prev=l;
			else prev=prev+1;
		}
		if(j==n) return i;
	}
    return 0;
}*/

/*int main()
{
	int arr[]={1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2};
	vector<int> heights(arr,arr+sizeof(arr)/sizeof(int));
	cout<<minLevel(heights)<<endl;
	return 0;
}
*/

int minLevel(vector<int> const &heights) 
{
	int l=0,r=1000000000;
	int i,n=heights.size();
	while(l<r)
	{
		int mid=(l+r)/2;int p=0;
		FF(i,n)
		{
			int low=heights.at(i)-mid;
			int hig=heights.at(i)+mid;
			if(p>=hig) break;
			else if(p<low) p=low;
			else p+=1;
		}
		if(i==n) r=mid; 
		else l=mid+1;
	}
	return r;
}
