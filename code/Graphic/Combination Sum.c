class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::sort(candidates.begin(),candidates.end());
        vector<int>tmp;clearVector(rs);this->candidates=candidates;
        this->target=target;
        dfs(tmp,0,0);
        return rs;
    }
private:
	vector<vector<int> >rs;
	vector<int>candidates;
	int target;
	void clearVector(vector<vector<int> >&rs)
	{
		int len=rs.size();
		while(len--)
			rs.pop_back();
	}

	void dfs(vector<int>&tmp,int val,int index)
	{
		if(val==target)
			rs.push_back(tmp);
		else if(index==candidates.size())
			return;
		else
		{
			int mx=(target-val)/candidates[index];
			for(int i=0;i<=mx;i++)
			{
				for(int j=1;j<=i;j++)
					tmp.push_back(candidates[index]);
				dfs(tmp,val+candidates[index]*i,index+1);
				for(int j=1;j<=i;j++)
					tmp.pop_back();
			}
		}

	}
};