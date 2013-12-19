#include <vector>
#include <string>
using namespace std;

string find(int n) 
{
	vector<int>global(1001,0);
	for(int i=2;i<=n;i++)
	{
		if(global[i]==0)
		{
			for(int j=2;j<=n;j++)
			{
				if(i+j>n) break;
				if((i+j)%j==0) global[i+j]=1;
			}
		}
	}
	if(global[n]==0) return "Brus";
	return "John";
}