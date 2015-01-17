#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int*rs1=new int[triangle.size()];
        int*rs2=new int[triangle.size()];
        for(int i=triangle.size()-1;i>=0;i--)
        {
        	int len=i;
        	if(i==triangle.size()-1)
        		for(int j=0;j<=i;j++)
        			rs1[j]=triangle[i][j];
        	else
        	{
        		for(int j=0;j<=i;j++)
        			rs2[j]=triangle[i][j]+min(rs1[j],rs1[j+1]);
        		for(int j=0;j<=i;j++)
        			rs1[j]=rs2[j];
        	}
        }
        return rs1[0];
    }
};

int main()
{
    int arr[]={-10};
    vector<int>tmp(arr,arr+1);
    vector<vector<int> >rs;
    rs.push_back(tmp);
    Solution solution;
    std::cout<<solution.minimumTotal(rs)<<endl;
    return 0;
}