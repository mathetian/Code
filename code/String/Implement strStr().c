class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l1=strlen(haystack);
        int l2=strlen(needle);
        int mxIndex=l1-l2;
        if(l2>l1)
        	return NULL;
        int i,j;
        for(i=0;i<=mxIndex;i++)
        {
        	for(j=0;j<l2;j++)
        	{
        		if(haystack[i+j]!=needle[j])
        			break;
        	}
        	if(j==l2)
        		return haystack+i;
        }
        return NULL;
    }
};