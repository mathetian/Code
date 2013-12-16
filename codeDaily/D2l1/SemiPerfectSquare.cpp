#include <vector>
#include <string>
using namespace std;

/*string check(int N) {
	vector<int>r;
    vector<int>r1;
    for(int i=1;i<=32;i++) 
    {
    	r.push_back(i*i);
    	r1.push_back(i*i*i);
    }
   	int i=1;
   	while(i<=32&&r1.at(i-1)<N) i++;
   	if(i>32) return "No";
   	while(i<=32&&r.at(i-1)<=N)
   	{
   		int a=N%r.at(i-1);
   		if(a==0) return "Yes";
   		i++;
   	}
   	return "No";
}*/

string check(int N) {
	vector<int>r;
	for(int i=1;i<=32;i++) r.push_back(i*i);
	int i=31;
	while(i>=0)
	{
		if(r.at(i)>N)
		{
			i--;
			continue;
		} 
		if(r.at(i)==N) return "Yes";
		int r1=N/r.at(i);
		if(r1>=i+1) return "No";
		if(N%r.at(i)==0) return "Yes";
		i--;
	}
	return "No";
}
