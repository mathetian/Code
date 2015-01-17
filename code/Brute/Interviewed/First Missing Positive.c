class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s=0;
        for(int i=0;i<n;i++)
        {
            if(A[i]>0)
                A[s++]=A[i]-1;
        }
        if(s==0)
            return 1;

        for(int i=0;i<s;i++)
        {
            if(A[i]==i)
                continue;
            // A[j] > s
            int j=A[i];
            while(j<s&&j!=i&&A[j]!=j)
            {
                int tmp=A[j];
                A[j]=j;j=tmp;
            }
            if(j<s&&A[j]!=j)
                A[i]=i;
        }
        for(int i=0;i<s;i++)
            if(A[i]!=i)
                return i+1;
        return s+1;
    }
};