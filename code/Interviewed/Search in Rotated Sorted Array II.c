class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int low=0,high=n-1;
       	while(low<=high)
       	{
       		int mid=(low+high)/2;
       		int v2=A[mid];
       		if(target==v2)
       			return true;
       	
     			int v1=A[low],v3=A[high];
          if(v1==v2)
          {
            int i=mid-1;
            while(low<=i && A[i] == v2) i--;

            if(low>i) low=mid+1; else high = i;
          }
          else if(v1 < v2)
          {
              if(target<v2&&target>=v1) high=mid-1;
              else low=mid+1;
          }
          else
          {
              if(target>v2&&target<=v3) low=mid+1;
              else high=mid-1;
          }
       	}
       	return false;
    }
};

Search(set):
    if size of set is 1 and set[0] == item 
        return info on set[0]
    divide the set into parts A and B
    if A is sorted and the item is in the A's range
        return Search(A)
    if B is sorted and the item is in the B's range
        return Search(B)
    if A is not sorted
        return Search(A)
    if B is not sorted
        return Search(B)
    return "not found"