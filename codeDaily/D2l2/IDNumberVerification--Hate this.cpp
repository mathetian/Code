#include <vector>
#include <string>
using namespace std;
//Don't know anything for 86. Hate this problem.
string verify(string const &id,
              vector<string> const &regionCodes) {
    if(id.size()!=18) return "Invalid";
    string a=id.substr(0,6);
    string b=id.substr(6,8);
    string c=id.substr(14,4);
    if(a.at(0)=='0') return "Invalid";
    int i=0;
    for(i=0;i<regionCodes.size();i++)
    {
    	if(regionCodes.at(i)==a) break;
    }
    if(i==regionCodes.size()) return "Invalid";

    string y=b.substr(0,4),m=b.substr(4,2),d=b.substr(6,2);

    int iy=atoi(y.c_str()),im=atoi(m.c_str()),id1=atoi(d.c_str());
    if(im==2&&id1==29)
    {
    	if(iy%4==0)
    	{
    		if(iy%100==0)
    		{
    			if(iy%400==0){}
    			else return "Invalid";
    		}
    	}
    	else return "Invalid";
    }
    else
    {
    	if(im>12||id1>31||im<=0||id1<=0) return "Invalid";
    	if(iy<1900||iy>=2012) return "Invalid";
    	if(im==2){if(id1>=29) return "Invalid";}
    	else
	    	switch(im)
	    	{
	    	case 1:;
	    	case 3:;
	    	case 5:;
	    	case 7:;
	    	case 8:;
	    	case 10:;
	    	case 12:break;
	    	default:if(id1==31) return "Invalid";
	    	}
    }
    if(c.substr(0,3)=="000") return "Invalid";
   	int sum=0;
   	for(int i=0;i<17;i++)
   		sum=(2*sum+id.at(i)-'0');
   	sum*=2;
   	sum=(1-sum)%11;
   	if(sum<0) sum+=11;
   	//cout<<"sum:"<<sum<<endl;
   	if(id.at(17)=='X')
   	{
   		if(sum!=10) return "Invalid";
   	}
   	else if(id.at(17)!=sum+'0') return "Invalid";
   	if(id.at(16)%2==0) return "Female";
   	return "Male";
}
