#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int> > getSubsets(vector<int>arr)
{
	int n=arr.size();
	vector<vector<int> >rs;
	int m=1<<n;
	for(int i=0;i<m;i++)
	{
		vector<int> t;
		for(int j=0;j<n;j++)
		{
			if((i&(1<<j))!=0) t.push_back(arr.at(j));
		}	
		rs.push_back(t);
	}
	return rs;
}

int main()
{
	return 0;
}