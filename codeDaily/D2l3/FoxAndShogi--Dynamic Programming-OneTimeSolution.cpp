#include <vector>
#include <string>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)
#define N 1000000007
int differentOutcomes(vector<string> const &board) 
{
	int n=board.size();int i,j,k;
	vector<vector<int> > dp;int64 rs=1;
	FF(i,n)
	{
		vector<int> happy;
		FF(j,n)
		{
			if(board.at(j).at(i)=='.') continue;
			happy.push_back(j);
		}
		dp.push_back(happy);
	}
	FF(i,n)
	{
		vector<int> prev(n,0);
		FF(j,dp.at(i).size())
		{
			int row=dp.at(i).at(j),col=i;
			if(j==0)
			{
				if(board.at(row).at(col)=='U') FF(k,row+1) prev[k]=1;
				else for(k=row;k<n;k++) prev[k]=1;
				continue;
			}
			vector<int> prev2(n,0);
			if(board.at(row).at(col)=='U')
			{
				int cur=0;
				for(k=1;k<=row;k++)
				{
					cur+=prev[k-1];cur%=N;
					prev2[k]=cur;
				}
			}
			else
			{
				int cur=0;
				for(k=0;k<row-1;k++) cur+=prev[k];
				for(k=row;k<n;k++)
				{
					cur+=prev[k-1];cur%=N;
					prev2[k]=cur;
				}
			}
			swap(prev,prev2);
		}
		if(dp.at(i).size()==0) continue;
		int sum=0;
		FF(j,prev.size()) sum=(sum+prev.at(j))%N;
		//cout<<"("<<rs<<" "<<sum<<")";
		rs=(rs*sum)%N;
	}
    return rs;
}
