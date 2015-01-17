#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<utility>
using namespace std;

void print(vector<int>iVec)
{
    for(int i=0;i<iVec.size();i++)
        cout<<iVec[i]<<" ";
    cout<<endl;
}

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> rs1(rowIndex+1);
        vector<int> rs2(rowIndex+1);
        rs1[0]=1;
        for(int i=1;i<=rowIndex+1;i++)
        {
        	for(int j=0;j<i;j++)
        	{
        		if(j==0||j==i-1)
        			rs2[j]=1;
        		else
        			rs2[j]=rs1[j]+rs1[j-1];
        	}
        	rs1=rs2;
        }
        return move(rs1);
    }
};

int main()
{
    Solution solution;
    vector<int> rr=solution.getRow(3);
    print(rr);
    return 0;
}