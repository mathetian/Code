class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i=0;int j=0;
        while(j<n)
        {
        	A[i++]=A[j];
        	int k=j+1;
        	while(k<n&&A[k]==A[j])
        		k++;
        	j=k;
        }

        return i;
    }
};