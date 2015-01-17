/**not very perfect solution, maybe better**/
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::sort(num.begin(),num.end());int mx=0x3fffffff;
        int a=0;
        for(int i=0;i<num.size();i++)
        {
        	for(int j=num.size()-1;j>i+1;j--)
        	{
        		int val=num[i]+num[j];
        		for(int k=i+1;k<j;k++)
        		{
        			int val2=val+num[k];
                    if(mx>abs(val2-target))
                    {
                        a=val2;mx=abs(val2-target);
                    }
                    else if(mx==abs(val2-target)&&val2<=target)
                    {
                        a=val2;
                    }
        		}
        	}
        }
        return a;
    }
};