class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1=word1.size();int len2=word2.size();
        int m=max(len1,len2);
        vector<vector<int> >F(m+1,vector<int>(m+1,0));
        for(int i=0;i<=max(len1,len2);i++)
        {
            F[i][0]=i;F[0][i]=i;
        }
        	
        for(int i=1;i<=len1;i++)
        {
        	for(int j=1;j<=len2;j++)
        	{
        		if(word1[i-1]==word2[j-1])
        			F[i][j]=F[i-1][j-1];
        		else
        			F[i][j]=min(F[i-1][j-1],min(F[i-1][j],F[i][j-1]))+1;
        	}
        }
        return F[len1][len2];
    }
};