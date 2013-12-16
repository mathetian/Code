#include <vector>
#include <string>
#include <iostream>
using namespace std;

string minNumber(string const &num) {
    string r=num;
    for(int i=0;i<r.size();i++)
    {
    	int less='0';int big=r.at(i);
    	if(i==0) less+=1;
    	int k=r.size()-1;
    	for(int j=r.size()-1;j>=i+1;j--)
    	{
    		int r1=r.at(j);
    		if(r1>=less&&r1<big)
    		{
    			if(r.at(k)>=less)
    			{
    				if(r1<r.at(k)) k=j;
    			}
    			else k=j;
    			
    		}
    	}
    	if(r.at(k)>=less&&r.at(k)<big)
    	{
    		char tmp=r.at(k);
    		r[k]=r[i];r[i]=tmp;
    		break;
    	}
    }
    return r;
}

/*int main()
{
	cout<<minNumber("90000000000000000000000000001000000000000")<<endl;
	return 0;
}
*/