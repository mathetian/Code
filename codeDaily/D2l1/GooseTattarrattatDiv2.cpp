#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

typedef map<char,int> _tciMap;
int getmin(string const &S) {
    _tciMap _ciMap;int mx=0;
    for(int i=0;i<S.size();i++)
    {
    	char val=S.at(i);
    	if(_ciMap.find(val)!=_ciMap.end())
    		_ciMap[val]++;
    	else
    		_ciMap[val]=0;
    	mx=max(_ciMap[val],mx);
    }
    return S.size()-mx-1;
}