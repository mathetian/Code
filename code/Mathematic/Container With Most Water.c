// class Solution {
// public:
//     int maxArea(vector<int> &height) {
//         // Start typing your C/C++ solution below
//         // DO NOT write int main() function
//         vector<pair<int,iiP>>rs;
//         iiP item;item.first=0;item.second=height[0];
//         int v=0;rs.push_back(make_pair(v,item));int mx=0;
//         for(int i=1;i<height.size();i++)
//         {
//             if(height[i]>=rs[i-1].second.second)
//             {
//                 item.first=rs[i-1].second.first+1;
//                 item.second=rs[i-1].second.second;
//                 v=item.first*item.second;
//                 rs.push_back(make_pair(v,item));
//             }
//             else
//             {
//                 int j=i-1;
//                 while(j>=0&&rs[j].second.second>=height[i])
//                     j--;
//                 if(j>=0)
//                 {
//                     item.first=rs[j].second.first+i-j;
//                     item.second=rs[j].second.second;
//                     v=item.first*item.second;
//                     rs.push_back(make_pair(v,item));
//                 }
//                 else
//                 {
//                     item.first=i;
//                     item.second=height[i];
//                     v=item.first*item.second;
//                     rs.push_back(make_pair(v,item));
//                 }
//             }
//             mx=max(mx,v);
//         }
//         return mx;
//     }
// private:
//     typedef pair<int,int> iiP;
// };

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) 
    {
        int l=0, r=height.size()-1;int rs=0;
        while(l<r)
        {
            rs=max(rs, min(height.at(l),height.at(r))*(r-l));
            if(height.at(l)<height.at(r)) l++;
            else r--;
        }
        return rs;
    }

    int maxArea2(vector<int> &height) 
    {
        vector<int> width(height.size(), 0);
        stack<int> istk;
        for(int i=0;i<height.size();i++)
        {
            while(!istk.empty()&&height.at(istk.top())>=height.at(i))
                istk.pop();
            width[i]=istk.empty()?i:i-istk.top()-1;
            istk.push(i);
        }

        while(!istk.empty()) istk.pop();
        for(int i=height.size()-1;i>=0;i--)
        {
            while(!istk.empty()&&height.at(istk.top())>=height.at(i))
                istk.pop();
            width[i]+=(istk.empty()?height.size()-i-1:istk.top()-i-1);
            istk.push(i);
        }
        int rs=0;
        for(int i=0;i<height.size();i++)
            rs=max(rs,height.at(i)*(width.at(i)));
        return rs;
    }
};