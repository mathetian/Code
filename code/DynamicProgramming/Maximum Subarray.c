class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int mx_end_here=0;int mx_so_far=0;
        for(int i=0;i<n;i++)
        {
        	mx_end_here=max(0,mx_end_here+A[i]);
        	mx_so_far=max(mx_so_far,mx_end_here);
        }
        if(mx_so_far==0)
        {
        	mx_so_far=-0x3fffffff;
        	for(int i=0;i<n;i++)
        		mx_so_far=max(mx_so_far,A[i]);
        }
        return mx_so_far;
    }

    int maxSubArray2(int A[], int n) 
    {
    
    }

};

/*def max_subarray(A):
    max_ending_here = max_so_far = 0
    for x in A:
        max_ending_here = max(0, max_ending_here + x)
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far*/