#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string rs1;
        if(nRows==1)
        {
            return s;
        }

        int len=s.size();
        vector<vector<char> >rs(nRows);
        int i=0;
        while(i<len)
        {
          for(int j=0;j<nRows&&i<len;j++,i++)
            rs[j].push_back(s[i]);
          for(int j=nRows-2;j>=1&&i<len;j--,i++)
            rs[j].push_back(s[i]);
        }
       
        for(i=0;i<nRows;i++)
        { 
          for(int j=0;j<rs[i].size();j++)
            rs1.push_back(rs[i][j]);
        }
        return rs1;
    }

    string convert1(string s, int nRows) { 
        
        if (nRows == 1) return s;
        string result;
        if (s.size() == 0) return result;

        int delta = nRows*2-2;
        for (int i = 0; i < nRows; i++) {
            for (int j = i; j < s.size(); j += delta) {
                result += s[j];
                if (i == 0 || i == nRows-1) continue;
                if (j + (nRows-i-1)*2 < s.size())
                    result += s[j+(nRows-i-1)*2];
            }
        }
        return result;
    }
};

int main()
{
  Solution solution;
  std::cout<<solution.convert("PAYPALISHIRING",2)<<std::endl;
  return 0;
}