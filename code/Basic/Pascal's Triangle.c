#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<utility>
using namespace std;
void print(vector<vector<int> >iVecs)
{
    for(int i=0;i<iVecs.size();i++)
    {
        vector<int>tmp=iVecs[i];
        for(int j=0;j<tmp.size();j++)
        {
            std::cout<<tmp[j]<<" ";
        }
        std::cout<<endl;
    }
    std::cout<<endl;
}

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >rs1;
        if(numRows==0)
             return move(rs1);
        vector<int>tmp;tmp.push_back(1);
        rs1.push_back(tmp);
        for(int i=1;i<numRows;i++)
        {
        	clearVector(tmp);
        	for(int j=0;j<=i;j++)
        	{	
        		if(j==0||j==i)
        			tmp.push_back(1);
        		else
                {
                    tmp.push_back(rs1[i-1][j]+rs1[i-1][j-1]);
                }
        			
        	}
        	rs1.push_back(tmp);
        }
        return move(rs1);
    }
private:
    void clearVector(vector<int> &iVec)
    {
        int s=iVec.size();
        while(s-->0) iVec.pop_back();
    }
};



int main()
{
    Solution solution;
    print(solution.generate(3));
    return 0;
}