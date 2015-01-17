#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int m=matrix.size(); vector<int>rs;
        if(m==0) return rs;
        int n=matrix[0].size(), t1=n/2+n%2, t2=m/2+m%2;
        int tim=min(t1,t2);
        for(int i=0;i<tim;i++)
        {
            int num=n-2*i;int k=i+num-1;//1 0
            int num2=m-2*i;int l=i+num2-1;//3 2
            if(num==1||num2==1)
            {
                if(num==1)
                {
                    for(int j=0;j<num2;j++)
                        rs.push_back(matrix[i+j][i]);
                }
                else
                {
                    for(int j=0;j<num;j++)
                        rs.push_back(matrix[i][i+j]);
                }
                break;
            }

            for(int j=0;j<num-1;j++)
                rs.push_back(matrix[i][j+i]);
               
            for(int j=0;j<num2-1;j++)
                rs.push_back(matrix[i+j][k]);
                
            for(int j=0;j<num-1;j++)
                rs.push_back(matrix[l][k-j]);
                
            for(int j=0;j<num2-1;j++)
                rs.push_back(matrix[l-j][i]);                
        }
        return rs;
    }
};

int main()
{
    Solution solution;
    vector<vector<int> >matrix;
    vector<int>a1;
    a1.push_back(7);
    matrix.push_back(a1);
    a1.pop_back();
    a1.push_back(6);
    matrix.push_back(a1);
    a1.pop_back();
    a1.push_back(9);
    matrix.push_back(a1);

    a1=solution.spiralOrder(matrix);
    for(int i=0;i<a1.size();i++)
        std::cout<<a1[i]<<endl;
    return 0;

}