#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct less_than_key{
    bool operator() (const string& s1, const string& s2)
    {
    	int i=0,j=0;
    	while(i<s1.size()&&j<s2.size())
    	{
    		if(s1.at(i)<s2.at(i)) return 1;
    		if(s1.at(i)>s2.at(i)) return 0;
    		i++;j++;
    	}
    	if(i<s1.size()) return 0;
    	return 1;
    }
};

string convert(int n)
{
	string rs3;
	while(n>0)
	{
		rs3.push_back(n%10+'0');
		n/=10;
	}
	reverse(rs3.begin(),rs3.end());
	return rs3;
}

vector<string> playList(int n) {
    int a=0;
    vector<string>rs;
    for(int i=1;i<=n;i++)
    	rs.push_back(convert(i));
    sort(rs.begin(),rs.end(),less_than_key());
    int m=n;
    if(n>50) m=50;
    vector<string>rs2;
    for(int i=0;i<m;i++) rs2.push_back(rs.at(i)+".mp3");
    return rs2;
}

/*int main()
{
	playList(3);
	return 0;
}
*/