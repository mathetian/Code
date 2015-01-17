#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <iostream>
using namespace std;

struct ITEM_t
{
    string str;
    int parent, num, index;
    int step;
    ITEM_t(string sr, int p, int n, int i, int s)
    {
      str = sr; parent = p; num = n; index = i;
      step = s;
    }
};

typedef struct ITEM_t ITEM;

class Solution 
{
vector<vector<string> > rs;
set<string> flags;
queue<string> steps;
vector<string> items;

void clearitems()
{
  vector<string> tmp;
  swap(items, tmp);
}
public:
    vector<vector<string> > findLadders(string start, string end, set<string> &dict) 
    {
      
    }
};

int main()
{
  return 0;
}