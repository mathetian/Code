class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==1&&A[0]==0)
          return true;
        int mx=0;int i;
        for(i=0;i<n&&i<=mx;i++)
        { 
          int step=A[i];
          mx=max(mx,i+step);
        }
        if(mx>=n-1)
          return true;
        return false;
    }
};