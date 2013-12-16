#include <vector>
#include <string>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

/*Greedy algorithm, Boundary situation*/
string minNumber(string const &digits) 
{
	int i,j;string a,b,c,d;string rs;
	FF(i,digits.size())
	{
		if(digits.at(i)=='0') continue; a.clear();
		FF(j,i){b=c=a;b.push_back(digits.at(j));c.insert(0,1,digits.at(j));a=b<c?b:c;}
		a+=digits.substr(i+1);a.insert(0,1,digits.at(i));if(rs.size()==0) rs=a; else rs=rs>a?a:rs;
	}	
    return rs;
}
