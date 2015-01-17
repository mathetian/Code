class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int begin=0,end=0;
        int mxend=0;int step=0;
        while(mxend<n-1)
        {
        	step++;
        	for(int i=begin;i<=end;i++)
        		mxend=max(mxend,i+A[i]);
        	begin=end+1;
        	end=mxend;
        }
        return step;
    }
};