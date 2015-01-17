#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) 
    {
        int n = height.size();
        vector<int> width(n,0);
        stack<int> istk;
        for(int i=0;i<height.size();i++)
        {
            int h=height.at(i);
            while(istk.empty() == false && height.at(istk.top()) >= h)
            { istk.pop();}
            width[i]=istk.empty()==true?i:i-istk.top()-1;
            istk.push(i);
        }

        while(istk.empty()==false) istk.pop();
        for(int i=height.size()-1;i>=0;i--)
        {
            int h = height.at(i);
            while(istk.empty() == false && height.at(istk.top()) >= h)
            { istk.pop(); }
            width[i]+=istk.empty()==true?(height.size()-i-1):istk.top()-i-1;
            istk.push(i);
        }
        int m=0;
        for(int i=0;i<height.size();i++)
            m=max(m,height.at(i)*(width.at(i)+1));
        return m;
    }   
};