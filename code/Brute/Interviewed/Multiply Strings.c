class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l1=num1.size(), l2=num2.size();
        vector<int>rs(l1+l2+1,0);
        if(num1.size()==1&&num1[0]=='0')
            return "0";
         if(num2.size()==1&&num2[0]=='0')
            return "0";
        for(int i=l1-1;i>=0;i--)
        {
        	for(int j=l2-1;j>=0;j--)
        	{
        		int v=(num1[i]-'0')*(num2[j]-'0');
        		int p1=l1-1-i;
        		int p2=l2-1-j;
        		rs[p1+p2]+=v;
        	}
        }
        for(int i=0;i<l1+l2;i++)
        {
        	if(rs[i]>0)
        	{
        		rs[i+1]=rs[i+1]+rs[i]/10;
        		rs[i]=rs[i]%10;
        	}
        }
        while(rs[rs.size()-1]==0)
        	rs.pop_back();
        string num="";
        for(int i=rs.size()-1;i>=0;i--)
        	num.push_back(rs[i]+'0');
        return num;
    }
};