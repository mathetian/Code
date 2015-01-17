#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) 
    {
        if(n <= 2) return 0;
        vector<int> l(n, 0);
        vector<int> r(n, 0);
        l[0] = A[0];r[n-1] = A[n-1];
        int i;for(i = 1;i < n;i++)
            l[i] = max(l[i-1], A[i]);
        for(i = n-2;i >= 0;i--)
            r[i] = max(r[i+1], A[i]);
        int rs = 0;
        for(i = 1;i < n-1;i++)
        {
            int t = min(l[i],r[i]);
            if(t > A[i]) rs += (t-A[i]);
        }
        return rs;
    }
};

int main()
{
    return 0;
}