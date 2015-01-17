class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int>hash(256,-1);
        int len=0;
        for(int i=0,j=0;i<s.size();i++)
        {
        	if(hash[s[i]]==-1)
        	{
        		hash[s[i]]=i;
        		if(i-j+1>len)
        			len=i-j+1;
        	}
        	else
        	{
        		int npos=hash[s[i]];
        		while(j<=npos)
        			hash[s[j]]=-1,j++;
        		hash[s[i]]=i;
        	}
        }
        return len;
    }
};