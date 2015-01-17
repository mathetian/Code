class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       int i;
       for(i=0;i<n;i++)
       {
       		if(A[i]>target)
       			break;
       		else if(A[i]==target)
       			break;
       }
       if(i<n&&A[i]==target)
       	return i;
       return i;
    }
};