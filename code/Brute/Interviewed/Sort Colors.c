class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s2=0,s3=n-1;
        int num1=0,num2=0,num3=0;
        for(int i=0;i<=s3;)
        {
        	if(A[i]==2)
        	{
        		swap(A+i,A+s3);
        		s3--; num3++;
        	}
        	else if(A[i]==1)
        	{
        		num2++; i++;
        	}
        	else
        	{
        		swap(A+s2,A+i);
        		s2++; i++; num1++;
        	}
        }
    }
private:
    void swap(int*a,int*b)
    {
        int tmp=*a;
        *a=*b;
        *b=tmp;
    }
};