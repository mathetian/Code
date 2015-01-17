/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

 struct Interval_less {
    bool operator ()(Interval const& a, Interval const& b) const {
        if (a.start < b.start) return true;
        return false;
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval>rs;
        std::sort(intervals.begin(),intervals.end(),Interval_less());
        Interval tmp;int index=0;
       
        while(index<intervals.size())
        {
        	tmp.start=intervals[index].start;
        	tmp.end=intervals[index].end;
        	int end=tmp.end;index++;
        	while(index<intervals.size())
        	{
	        	if(intervals[index].start>tmp.end)
	        		break;
	        	else
	        		tmp.end=max(tmp.end,intervals[index].end);
                index++;
       	 	}
       	 	rs.push_back(tmp);
        }
        return rs;
    }
};

int main()
{
    Interval i1(1,4)
}
