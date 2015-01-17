class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s=path.size();
        vector<string>fin;
	    int i=0;
	    while(i<s)
	    {
	    	while(i<s&&path[i]=='/') i++;
	    	if(i==s) break;
	    	int j=i+1;
	    	while(j<s&&path[j]!='/') j++;
	    	string tmp=path.substr(i,j-i);
	    	if(tmp==".")
	    	{ }
	    	else if(tmp=="..")
	    	{
	    		if(fin.size()>=1)
	    			fin.pop_back();
	    	}
	    	else fin.push_back(tmp);
	    	i=j;
	    }
	    string rs="";
	    for(int i=0;i<fin.size();i++)
	    	rs=rs+"/"+fin[i];
	    if(fin.size()==0)
	    	return "/";
	    return rs;
    }
};