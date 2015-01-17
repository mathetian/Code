class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        this->S=S;
        sort(this->S.begin(),this->S.end());
        vector<int>tmp;int len=S.size();
        clearVector(rs);
        dfs(0,len,tmp);
        return rs;
    }
private:
	vector<vector<int> >rs;
	vector<int>S;
	void clearVector(vector<vector<int> >&rs)
	{
		int len=rs.size();
		while(len--)
			rs.pop_back();
	}
	void dfs(int pos,int len,vector<int>&tmp)
	{
		if(pos==len)
			rs.push_back(tmp);
		else
		{
			dfs(pos+1,len,tmp);
			tmp.push_back(S[pos]);
			dfs(pos+1,len,tmp);
			tmp.pop_back();
		}
	}
};
