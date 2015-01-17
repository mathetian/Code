class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int flag=1;
        if(x<0) flag=-1;
        int rs=0;x=max(x,-x);
        while(x!=0)
        {
            rs=rs*10+x%10;
            x=x/10;
        }
        return rs*flag;
    }
};