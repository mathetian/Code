class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int f1=0,f2=0;
        int l1=matrix.size();
        if(l1==0)
        	return;
        int l2=matrix[0].size();
        if(l2==0)
        	return;

        int i, j;

        for(i=0;i<l1&&matrix[i][0]!=0;i++);
        if(i<l1) f1 = 1;
        for(i=0;i<l2&&matrix[0][i]!=0;i++);
        if(i<l2) f2=1;

        for(i=1;i<l1;i++)
        {
        	for(j=1;j<l2;j++)
        	{
        		if(matrix[i][j]==0)
        		{
        			matrix[0][j]=0;
        			matrix[i][0]=0;
        		}
        	}
        }
        for(i=1;i<l1;i++)
        {
        	if(matrix[i][0]==0)
        	{
        		for(j=0;j<l2;j++)
        			matrix[i][j]=0;
        	}
        }
        for(j=1;j<l2;j++)
        {
        	if(matrix[0][j]==0)
        	{
        		for(i=0;i<l1;i++)
        			matrix[i][j]=0;
        	}
        }
        if(f1==1)
        {
        	for(i=0;i<l1;i++)
        		matrix[i][0]=0;
        }
        if(f2==1)
        {
        	for(j=0;j<l2;j++)
        		matrix[0][j]=0;
        }
    }
};