class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       	int low=0,high=n-1;
       	while(low<=high)
       	{
       		int mid=(low+high)/2;
       		int v2=A[mid];
       		if(target==v2)
       			return mid;
       	
   			  int v1=A[low],v3=A[high];

       		if(v1<v2)
       		{
       			if(target<=v2&&target>=v1)
       				high=mid-1;
       			else
       				low=mid+1;
       		}
       		else
       		{
       			if(target>=v2&&target<=v3)
       				low=mid+1;
       			else
       				high=mid-1;
       		}
       	}
       	return -1;
    }
};