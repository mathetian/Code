class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int>rs;
        if(n==0)
        {
          rs.push_back(-1);rs.push_back(-1);
          return rs;
        }
        int low=0;int high=n-1;int mid=(low+high)/2;
        while(high>=low)
        {
          mid=(low+high)/2;
          if(A[mid]==target)
            break;
          else if(A[mid]>target)
            high=mid-1;
          else
            low=mid+1;
        }
        if(A[mid]!=target)
       	{
       		rs.push_back(-1);
       		rs.push_back(-1);
       	}
       	else
       	{
       		int i;
       		for(i=mid;i>=0&&A[i]==target;i--);
       		int j;
       		for(j=mid;j<n&&A[j]==target;j++);
       	  int num=j-i-1;

            rs.push_back(i+1);
            rs.push_back(j-1);

       	}
       	return rs;
    }
};