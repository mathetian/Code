class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        clearVector(rs);
        clearVector(rs1);

        sort(S.begin(),S.end());
       	if(S.size()==0)
       		return rs;

       	int i=0;
       	while(i<S.size())
       	{
       		int j=i+1;
       		while(j<S.size()&&S[j]==S[i])
       			j++;
       		rs1.push_back(make_pair(S[i],j-i));
       		i=j;
       	}
       	vector<int>tmp;
       	dfs(0,rs1.size(),tmp);
       	return rs;
    }
private:
	vector<vector<int> >rs;
	typedef pair<int,int>iPair;
	vector<iPair>rs1;
	void clearVector(vector<vector<int> >&rs)
	{
		int len=rs.size();
		while(len--)
			rs.pop_back();
	}

	void clearVector(vector<iPair>&rs1)
	{
		int len=rs1.size();
		while(len--)
			rs1.pop_back();
	}

	void dfs(int pos,int len,vector<int>&tmp)
	{
		if(pos==len)
			rs.push_back(tmp);
		else
		{
			int tim=rs1[pos].second;
			int val=rs1[pos].first;
			dfs(pos+1,len,tmp);

			for(int i=1;i<=tim;i++)
			{
				tmp.push_back(val);
				dfs(pos+1,len,tmp);
			}

			for(int i=1;i<=tim;i++)
				tmp.pop_back();
		}
	}
};