#include <unordered_set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      items.clear();
      queue<ITEM>sQ;
    	dict.insert(start);dict.insert(end);
    	int i;int len=start.length();
      ITEM t1;t1.str=start;t1.step=1;
    	sQ.push(t1);
    	while(!sQ.empty())
    	{
    		t1=sQ.front();sQ.pop();
    		if(t1.str==end)
    			return t1.step;
    		for(int i=0;i<len;i++)
    		{
    			int old=t1.str[i];
    			for(int j=0;j<26;j++)
    			{
    				t1.str[i]=j+'a';
    				if(dict.find(t1.str)==dict.end())
    					continue;
    				ITEM t2;t2.str=t1.str;t2.step=t1.step+1;
    				sQ.push(t2);
    			}
    			t1.str[i]=old;
    		}
    	}
      return 0;
    }
private:
	typedef struct {
        	string str;int step;
    }ITEM;
   	vector<ITEM>items;
};

int main()
{
  unordered_set<string>dict;dict.insert("hot");dict.insert("dog");
  Solution solution;
  solution.ladderLength("hot","dog",dict);
  return 0;
}

typedef struct{
  string str;int step;
}ITEM;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_set<string> visited;
        visited.insert(start);
        queue<ITEM>sQ;ITEM item;
        item.str=start;item.step=1;
        sQ.push(item);
        int len=start.size();
        while(!sQ.empty())
        {
          item=sQ.front();sQ.pop();
          if(item.str==end)
            return item.step;
          for(int i=0;i<len;i++)
          {
            char old=item.str[i];
            for(int j=0;j<26;j++)
            {
              item.str[i]=j+'a';
              if(dict.find(item.str)!=dict.end()&&visited.find(item.str)==visited.end())
              {
                ITEM item2;item2.str=item.str;item2.step=item.step+1;
                visited.insert(item2.str);sQ.push(item2);
              }
            }
            item.str[i]=old;
          }
        }
        return 0;
    }
};
