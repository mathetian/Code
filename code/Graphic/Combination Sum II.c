class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::sort(num.begin(),num.end());
       	clearVector(rs);this->num=num;this->target=target;
       	vector<int>tmp;
        dfs(tmp,0,0);
        vector<vector<int> >rs2;
        int i=0;
        while(i<rs.size())
        {
        	int j=0;
        	for(;j<rs2.size();j++)
        	{
        		if(rs[i]==rs2[j])
        			break;
        	}
        	if(j==rs2.size())
        		rs2.push_back(rs[i]);
        	i++;
        }
        return rs2;
    }
private:
	vector<vector<int> >rs;vector<int>num;int target;
	void clearVector(vector<vector<int> >&rs)
	{
		int len=rs.size();
		while(len>0)
		{
			rs.pop_back();len--;
		}
	}
	void dfs(vector<int>&tmp,int val,int index)
	{
		if(val==target)
			rs.push_back(tmp);
		else if(index==num.size())
			return;
		else
		{
			if(val+num[index]<=target)
			{
				tmp.push_back(num[index]);
				dfs(tmp,val+num[index],index+1);
				tmp.pop_back();
			}
			dfs(tmp,val,index+1);
		}
	}
};