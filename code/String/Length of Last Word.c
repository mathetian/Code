class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       	int len=strlen(s);
       	if(len==0)
       		return 0;
       	int end=len-1;
       	while(end>=0&&isspace(*(s+end)))
       		end--;
       	if(end<0)
       		return 0;
       	int end2=end;
       	while(end2>=0&&isspace(*(s+end2))==false)
       		end2--;
       	return end-end2;
    }
};