#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >rs;
        std::sort(num.begin(),num.end());
        vector<int> tmp(3,0);
        for(int i=0;i<num.size();i++)
        {
            tmp[0]=num.at(i);
            if(i!=0&&num.at(i)==num.at(i-1)) continue;
            int j=i+1, k=num.size()-1;
            while(j<k)
            {
                int t=num.at(i)+num.at(j)+num.at(k);
                if(t > 0) k--; else if(t < 0) j++;
                else
                {
                    tmp[1]=num.at(j);tmp[2]=num.at(k);
                    if(rs.size()==0||tmp!=rs.at(rs.size()-1))
                        rs.push_back(tmp);
                    ++j;--k;
                }
            }
        }
        return rs;
    }
};

int main()
{
    Solution solution;int aa[]={12,13,12,13,-3,3,11,7,10,5,1,6,6,14,2,-8,-1,-4,3,-10,3,-13,7,-15,12,10,-2,-14,3,-3,-7,0,-12,12,-1,0,0,-13,-8,-12,7,0,9,-1,-8,-12,6,6,-1,-13,3,-13,-11,-4,9,-14,-9,14,9,2,-3,-13,9,0,-15,-15,7,-8,-12,6,-5,10,14,-11,-6,-9,14,8,4,-10,10,-8,14,6,3,8,0,2,8,-6,11,12,-3,5,-3,-11,6,11,-4,1,-6,-1,-4,-7,3,-2,-9,-5,-9,10,0,8,-12,-8,-1};
    cout<<sizeof(aa)/sizeof(int)<<endl;
    vector<int>bb(aa,aa+sizeof(aa)/sizeof(int));
    vector<vector<int> > rs = solution.threeSum(bb);
    for(int i = 0;i < rs.size();i++)
    {
        for(int j = 0;j < rs[i].size();j++)
            cout<<rs[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}