#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<char>rs=trim(str);
        if(rs.size()==0)
            return 0;
        int val=0;
        int flag=1;
        switch(rs[0])
        {
        case '+' : flag = 1; break;
        case '-' : flag = -1; break;
        default:
            {
                if(isdigtal(rs[0])) val = rs[0] - '0';
                else return 0;
            }
        }
       
        int oldVal=val;
        for(int i=1;i<rs.size();i++)
        {
            if(isdigtal(rs[i]))
            {
                val=val*10+rs[i]-'0';
                if(flag==1)
                {
                    if(val>=214748365&&i<rs.size()-1)
                        return 2147483647;
                    if(val==214748364)
                    {
                        if(i<rs.size()-2)
                            return 2147483647;
                        if(i==rs.size()-2&&rs[i+1]>='7')
                            return 2147483647;
                    }
                }
                else
                {
                    if(val>=214748365&&i<rs.size()-1)
                        return -2147483648;
                    if(val==214748364)
                    {
                        if(i<rs.size()-2)
                             return -2147483648;
                           
                        if(i==(rs.size()-2)&&rs[i+1]>='8')
                            return -2147483648;
                    }
                }
            }
            else
                return flag*val;
        }
        return flag*val;
    }

private:
    vector<char> trim(const char*str)
    {
        vector<char>rs;
        int i=0;int len=strlen(str);
        while(i<len&&isspace(str[i]))
            i++;
        int j=len-1;
        while(j>=0&&isspace(str[j]))
            j--;
        if(i==j)
        {
            if(str[i]>='0'&&str[i]<='9')
            {
                rs.push_back(str[i]);
            }
            return rs;
        }
        int k=i+1;
        for(;k<=j;k++)
        {
            if(str[k]>='0'&&str[k]<='9')
            {

            }
            else
                break;
        }
        for(;i<k;i++)
            rs.push_back(str[i]);
        return rs;
    }

    bool isdigtal(char c)
    {
        if(c >= '0' && c <= '9')
            return 1;
        return 0;
    }
};

int main()
{
    Solution solution;
    std::cout<<solution.atoi("    1052223016k4")<<std::endl;
    return 0;
}