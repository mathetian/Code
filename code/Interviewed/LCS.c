#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int mx=1;
        iMap.clear();
        for(int i=0;i<num.size();i++)
        {
        	if(iMap.find(num[i])!=iMap.end())
        		continue;
        	iMap[num[i]]=1;
        	if(iMap.find(num[i]-1)!=iMap.end())
        		mx=std::max(mx,lrmx(num[i]-1,num[i]));
        	if(iMap.find(num[i]+1)!=iMap.end())
        		mx=std::max(mx,lrmx(num[i],num[i]+1));
        }
        return mx;
    }
private:
	map<int,int>iMap;
	int lrmx(int rkey,int lkey)
	{
		int rIndexKey=rkey-(iMap[rkey]-1);
		int lIndexKey=lkey+(iMap[lkey]-1);
        int r=lIndexKey-rIndexKey+1;
        iMap[rIndexKey]=iMap[lIndexKey]=r;
        return iMap[rIndexKey];
	}
};

void print(vector<int>iVec)
{
    for(int i=0;i<iVec.size();i++)
        std::cout<<iVec[i]<<" ";
    std::cout<<endl;
}
int main()
{
    Solution solution;
    int arr[]={-1,1,0};
    vector<int>iVec(arr,arr+3);
    print(iVec);
    std::cout<<solution.longestConsecutive(iVec)<<endl;
}