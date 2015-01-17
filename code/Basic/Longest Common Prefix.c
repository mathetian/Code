class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(strs.size()==0)
          return "";
        int i=1;int len=strs[0].size();
        while(i<strs.size())
      {
        int j;
        for(j=0;j<len;j++)
        {
          if(strs[0][j]!=strs[i][j])
            break;
        }
        len=j;i++;
      }
      return strs[0].substr(0,len);
    }
};