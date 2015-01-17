class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >rs(n,vector<int>(n,0));
        int tim=n/2+n%2;int val=1;
        //i=0, a=0 len=2 b=
        for(int i=0;i<tim;i++)
        {
        	int a=i;int len=n-2*i;
        	int b=a+len-1;
            if(a==b)
            {
                rs[a][a]=val;
                break;
            }
        	for(int j=a;j<=b;j++,val++)
        		rs[a][j]=val;
        	for(int j=a+1;j<=b;j++,val++)
        		rs[j][b]=val;
        	for(int j=b-1;j>=a;j--,val++)
        		rs[b][j]=val;
        	for(int j=b-1;j>=a+1;j--,val++)
        		rs[j][a]=val;
        }

        return rs;
    }
};