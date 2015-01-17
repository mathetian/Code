#include <vector>
using namespace std;

struct Interval {
   int start;
   int end;
   Interval() : start(0), end(0) {}
   Interval(int s, int e) : start(s), end(e) {}
};
 
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
    {
        bool flag = true;vector<Interval> rs;
        for(int i=0;i<intervals.size();i++)
        {
            if(intervals[i].end < newInterval.start)
              rs.push_back(intervals.at(i));
            else if(intervals[i].start > newInterval.end)
            {
              if(flag==true)
              {
                rs.push_back(newInterval);
                flag = false;
              }
              rs.push_back(intervals[i]);
            }
            else
            {
              newInterval.start = min(newInterval.start, intervals[i].start);
              newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        if(flag==true) rs.push_back(newInterval);
        return rs;
    }
};