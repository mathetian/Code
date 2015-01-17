#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;


class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        clearVector(rs);
        vector<int>tmp;
        this->n=n;this->k=k;
        dfs(tmp,0,1);
        return rs;
    }
private:
	vector<vector<int> >rs;int n,k;
	void clearVector(vector<vector<int> >&rs)
	{
		int a=rs.size();
		while(a--)
			rs.pop_back();
	}

	void dfs(vector<int>&tmp,int num,int mxv)
	{
		if(num==k)
		{
			rs.push_back(tmp);
			return;
		}

		int rnum=k-num;
		if(mxv+rnum-1>n)
			return;
		else
		{
			dfs(tmp,num,mxv+1);
			tmp.push_back(mxv);
			dfs(tmp,num+1,mxv+1);
			tmp.pop_back();
		}
	}
};

int main()
{
	vector<vector<int> >rs;
	Solution solution;
	rs=solution.combine(4,2);
	for(int i=0;i<rs.size();i++)
	{
		for(int j=0;j<rs[i].size();j++)
			std::cout<<rs[i][j]<<" ";
		std::cout<<endl;
	}
	return 0;
}