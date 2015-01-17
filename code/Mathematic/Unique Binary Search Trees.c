class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0||n==1)
        	return 1;
        if(n==2)
        	return 2;
        int*arr=new int[n+1];
        arr[0]=arr[1]=1;
        arr[2]=2;
        for(int i=3;i<=n;i++)
    	{
    		int rs=0;
    		for(int j=0;j<=i-1;j++)
    			rs=rs+arr[j]*arr[i-1-j];
    		arr[i]=rs;
    	}
    	return arr[n];
    }
};