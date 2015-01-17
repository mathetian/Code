#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
using namespace std;

#include <assert.h>

class Solution {
public:
    string getPermutation(int n, int k) 
    {
    	vector<int> val(n, 0);
    	int i;for(i=0;i<n;i++)    val[i]=i+1;
    	t9[0] = 0;t9[1]=1;for(i=2;i<10;i++) t9[i]=t9[i-1]*i;
    	return get1(0,val,n,k);
    }

private:
	int t9[10];
	string get1(int pos, vector<int> val,int n,int k)
	{
		if(pos == n) return ""; 
		string rs;

		if(pos == n-1)
		{
			rs.push_back(val.at(0)+'0');
			return rs;
		}
		int m  = t9[n-pos-1];
		int t1 = k/m; if(k%m == 0) t1--;
		rs.push_back(val.at(t1)+'0');
		//cout<<m<<" "<<rs<<endl;
		int ss=val.size();
		for(int i=t1;i<ss-1;i++)
			val[i]=val[i+1];
		val.pop_back();
		return rs+get1(pos+1, val, n, k-t1*m);
	}
};

int main()
{
	Solution solution;
	std::cout<<solution.getPermutation(3,5)<<std::endl;
}