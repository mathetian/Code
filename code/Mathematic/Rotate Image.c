class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m=matrix.size();
        int half=m/2;
        for(int i=0;i<half;i++)
        {
        	int len=m-2*i;
        	for(int j=0;j<len-1;j++)
        	{
                int tmp=matrix[i+len-1-j][i];
                matrix[i+len-1-j][i]=matrix[i+len-1][i+len-1-j];
                matrix[i+len-1][i+len-1-j]=matrix[i+j][i+len-1];
                matrix[i+j][i+len-1]=matrix[i][i+j];
                matrix[i][i+j]=tmp;
        	}
        }
    }
};