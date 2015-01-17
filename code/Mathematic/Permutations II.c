#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

#include <assert.h>

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &n1) 
    {
        clearVector(rs1);clearVector(rs2);num = n1;
        sort(num.begin(),num.end());
        vector<int>rs;
        permute(rs,0,num.size());
        sortrs();
        return rs2;
    }
private:
    vector<vector<int> >rs1;
    vector<vector<int> >rs2;
    vector<int> num;

    void clearVector(vector<vector<int> > &rs)
    {
        vector<vector<int> > tmp;
        swap(tmp, rs);
    }
	
    void swap1(vector<int>&num,int a,int b)
    {
        int tmp=num[a];
        num[a]=num[b];
        num[b]=tmp;
    }

	void permute(vector<int> rs, int m,int n)
	{
		if(m==n)
            rs1.push_back(num);
		else
		{
            int k;
            for(k=m+1;k<n && num.at(k)==num.at(k-1);k++);
		    k=k-m;
            
            for(int i=0;i<=k;i++)
            {
            }
        }
	}

    int cmp(vector<int> &a1, vector<int> &a2)
    {
        assert(a1.size() == a2.size());
        for(int i=0;i<a1.size();i++)
        {
            if(a1.at(i) < a2.at(i))
                return -1;
            else if(a1.at(i) > a2.at(i))
                return 1;
        }
        return 0;
    }

    void sortrs()
    {
        rs2.push_back(rs1.at(0));
        int i,j;for(i=1;i<rs1.size();i++)
        {
            vector<int> tmp = rs1.at(i);
            for(j=i-1;j>=0;j--)
            {
                int flag = cmp(tmp, rs1.at(j));
                if(flag >= 0) break;
                rs1[j+1]=rs1[j];
            }
            rs1[j+1]=tmp;
        }
        for(i=1;i<rs1.size();i++)
        {
            if(cmp(rs1.at(i), rs1.at(i-1)) != 0)
                rs2.push_back(rs1.at(i));
        }
    }
};

int main()
{
    Solution solution;
    vector<int> num;
    num.push_back(2);num.push_back(2);
    num.push_back(3);num.push_back(3);num.push_back(3);
    solution.permuteUnique(num);
    return 0;
}