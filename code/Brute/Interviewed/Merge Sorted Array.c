/**Need Further process**/
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
     	int a=0,b=0;
     	int*c=new int[m+n];int d=0;
     	while(a<m&&b<n)
     	{
     		if(A[a]<B[b])
     			c[d++]=A[a++];
     		else
     			c[d++]=B[b++];
     	}
     	while(a<m)
     		c[d++]=A[a++];
     	while(b<n)
     		c[d++]=B[b++];
     	for(int i=0;i<d;i++)
     		A[i]=c[i];
    }

    void merge2(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int end = m + n - 1;
        m -= 1;
        n -= 1;
        while (m >= 0 && n >= 0) {
            if (A[m] > B[n]) 
                A[end--] = A[m--];
            else
                A[end--] = B[n--];
        }
        while (m >= 0) 
            A[end--] = A[m--];
        while (n >= 0)
            A[end--] = B[n--];
    }
};