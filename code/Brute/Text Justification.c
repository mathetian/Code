#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      vector<vector<string> >rs;
      vector<string>rs2;
      if(L==0)
      {
            string sp="";
            rs2.push_back(sp);
            return rs2;
      }
            
      if(words.size()==1&&words[0].size()==0)
      {
            string sp=getSpace(L);
            rs2.push_back(sp);
            return rs2;
      }
      int i=0;
      while(i<words.size())
      {
            //std::cout<<words[i]<<endl;
            int curLen=0;
            vector<string>rs1;
            while(i<words.size()&&curLen+words[i].size()<=L)
            {
                  curLen=curLen+words[i].size();
                  if(curLen!=L) curLen+=1;
                  rs1.push_back(words[i]);
                  i++;
            }
       	rs.push_back(rs1);
      }
      i=0;
      while(i<rs.size())
      {
            if(rs[i].size()==1)
       	{
       		string t;
       		t=rs[i][0];
       		t=t+getSpace(L-rs[i][0].size());
       		rs2.push_back(t);
       		i++;
       		continue;
       	}
            else if(i==rs.size()-1)
            {
                  string t=rs[i][0];int len=rs[i][0].size();
                  for(int j=1;j<rs[i].size();j++)
                  {
                        t=t+getSpace(1)+rs[i][j];
                        len=len+rs[i][j].size()+1;
                  }
                  t=t+getSpace(L-len);
                  rs2.push_back(t);

                  break;
            }
       	int mxSpace=L;
       	for(int j=0;j<rs[i].size();j++)
       		mxSpace-=rs[i][j].size();
       	int r=mxSpace/(rs[i].size()-1);
       	int remain=mxSpace%(rs[i].size()-1);
       	if(remain==0)
       	{
       		string t=rs[i][0];
       		for(int j=1;j<rs[i].size();j++)
       			t=t+getSpace(r)+rs[i][j];
       		rs2.push_back(t);
       	}
       	else
       	{
       		string t=rs[i][0];
       		for(int j=1;j<=remain;j++)
       			t=t+getSpace(1+r)+rs[i][j];
       		for(int j=remain+1;j<rs[i].size();j++)
       			t=t+getSpace(r)+rs[i][j];
       		rs2.push_back(t);
       	}
            i++;
      }
      return rs2;
    }
private:
	string getSpace(int len)
	{
            if(len==0)
                  return "";
		string rs3=" ";
		for(int i=1;i<len;i++)
			rs3+=" ";
		return rs3;
	}
};

int main()
{
      Solution solution;
      vector<string>rs4;rs4.push_back("a");
      vector<string>rs5=solution.fullJustify(rs4,1);
      for(int i=0;i<rs5.size();i++)
            std::cout<<rs5[i].size()<<endl;
      return 0;
}