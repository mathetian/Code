#include <vector>
#include <string>
#include <set>
using namespace std;

int minPresses(vector<string> const &lines) {
    set<string> _strSet;int step=0;
    for(int i=0;i<lines.size();i++)
    {
    	string s=lines.at(i);
    	if(i==0)
    	{
    		for(int j=0;j<=s.size();j++)
	    		_strSet.insert(s.substr(0,j));
	    	step=step+s.size()+1;
    		continue;
    	}
    	int k=0;
    	for(int j=0;j<=s.size();j++)
    	{
    		if(_strSet.find(s.substr(0,j))!=_strSet.end()) k=j;
    	}
    	string s1=lines.at(i-1);
    	if(k<s1.size())
    	{
    		step=step+2+s.size()-k;
    		step+=1;
    	}
    	else if(k<=s1.size()+2)
    	{
    		if(s.substr(0,s1.size())==s1) step=step+k-s1.size()+s.size()-k;
    		else step=step+2+s.size()-k;
    		step+=1;
    	}
    	else
    	{
    		step=step+2+s.size()-k;
    		step+=1;
    	}
    	for(int j=k;j<=s.size();j++)
    		_strSet.insert(s.substr(0,j));
    }
    return step;
}
