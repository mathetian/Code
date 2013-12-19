#include <vector>
#include <string>
#include <set>
using namespace std;

int possibleHandles(string const &familyName,
                    string const &givenName) {
    int n=familyName.size(),m=givenName.size();
    set<string>uName;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		string c=familyName.substr(0,i);
    		string d=givenName.substr(0,j);
    		c+=d;
    		uName.insert(c);
    	}
    }
    return uName.size();
}
