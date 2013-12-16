#include <vector>
#include <string>
using namespace std;

string wolf="wolf";

string check(string const &str) {
	int n=str.size();
	int i=0;int flag=1;
	while(i<n&&flag)
	{
		int j=i;
		while(j<n&&str.at(j)=='w') j++;
		int time=j-i;int end=j+time*3;

		if(j==i||j==n||end>n)	flag=0;
		for(int k=1;k<4&&flag;k++)
		{
			int s=j+(k-1)*time;
			for(int l=0;l<time&&flag;l++)
			{
				if(str.at(s+l)!=wolf.at(k))  flag=0;
			}
		}
		i=end;
	}
	if(flag==1) return "VALID";
	return "INVALID";
}
