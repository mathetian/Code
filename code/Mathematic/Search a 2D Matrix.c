class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.size()==0)
        	return false;
        int a=matrix.size();int b=matrix[0].size();
        int low=0;int high=a*b;
        while(low<high)
        {
        	int mid=(low+high)/2;
        	int a1=mid/b;int a2=mid%b;
        	if(matrix[a1][a2]==target)
        		return true;
        	else if(matrix[a1][a2]<target)
        		low=mid+1;
        	else
        		high=mid;
        }
        return false;
    }

    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.empty()) return false;
        int lf = 0;
        int rt = matrix.size() - 1;
        int column = matrix[0].size();
        while (lf <= rt) {
            int m = (lf + rt) / 2;
            if (target < matrix[m][0]) {
                rt = m - 1;
            }
            else if (target > matrix[m][column-1]) {
                lf = m + 1;
            }
            else {
                return isValid(matrix[m], target);
            }
        }
        return false;
    }
    bool isValid(vector<int>& row, int target) {
        int lf = 0;
        int rt = row.size() - 1;
        while (lf <= rt) {
            int m = (lf + rt) / 2;
            if (target == row[m]) {
                return true;
            }
            else if (target > row[m]) {
                lf = m + 1;
            }
            else {
                rt = m - 1;
            }
        }
        return false;
    }
};