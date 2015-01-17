class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        clearVector(rs);
        std::sort(num.begin(),num.end());
        permute(num,0,num.size());
        return rs;
    }
private:
	vector<vector<int> >rs;
	void clearVector(vector<vector<int> >&rs)
	{
		int len=rs.size();
		while(len--)
			rs.pop_back();
	}
	 void swap(vector<int>&num,int a,int b)
    {
        int tmp=num[a];
        num[a]=num[b];
        num[b]=tmp;
    }
	void permute(vector<int>&num, int m,int n)
	{
		if(m==n)
			rs.push_back(num);
		else
		{
			for(int i=m;i<n;i++)
			{
				swap(num,m,i);
				permute(num,m+1,n);
				swap(num,m,i);
			}
		}
	}
};