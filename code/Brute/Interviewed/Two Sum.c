 struct Interval_less {
    bool operator ()(pair<int,int> const& a, pair<int,int> const& b) const {
        if(a.second<b.second)
            return true;
        return false;
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<pair<int,int> >num;
        for(int i=0;i<numbers.size();i++)
            num.push_back(make_pair(i,numbers[i]));
        std::sort(num.begin(),num.end(),Interval_less());
       
        vector<int>rs;
        int i=0;int j=numbers.size()-1;
        while(i<j)
        {
        	if(num[i].second+num[j].second==target)
        	{
        		rs.push_back(num[i].first+1);
        		rs.push_back(num[j].first+1);
                std::sort(rs.begin(),rs.end());
        		break;
        	}
        	else if(num[i].second+num[j].second<target)
        		i++;
        	else
        		j--;
        }
        return rs;
    }
};