#include <vector>
#include <string>
#include <iostream>
using namespace std;

string simulate(vector<int> const &preference1,
                vector<int> const &preference2) {
    string b(preference1.size(),'0');
    int num=preference1.size();
    int i1=0,i2=0;int h=num/2+num%2;
    while(h>0)
    {
    	while(i1<num&&b[preference1[i1]-1]!='0') i1++;
    	if(i1<num)
            b[preference1[i1]-1]='1';
    	while(i2<num&&b[preference2[i2]-1]!='0') i2++;
    	if(i2<num)
            b[preference2[i2]-1]='2'; 
        h--;
    }
    return b;
}