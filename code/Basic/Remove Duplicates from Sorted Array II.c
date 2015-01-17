class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int index=0;
        int i=0;
        while(i<n)
        {
        	int j=i+1;
        	while(j<n&&A[j]==A[i])
        		j++;
        	int num=j-i;
        	if(num>=2)
        		A[index++]=A[i];
        	A[index++]=A[i];
        	i=j;
        }
        return index;
    }
};