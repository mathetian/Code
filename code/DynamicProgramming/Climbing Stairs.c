class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //f(n)=f(n-1)+f(n-2)
        int a = 1, b = 2;
        if(n <= 2) return n;
        while(n > 2)
        {
            int tmp = b; b = a + b;
            a = tmp; n--;
        }
        return b;
    }
};