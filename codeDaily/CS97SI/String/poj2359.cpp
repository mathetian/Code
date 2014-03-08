#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str, name;
	while(getline(cin,name))
		str += name;

	//f(n,k)=(f(n-1,k)+k) mod n，f(1,k)=0
	int r = 0, n = str.size();
	for(int i=2;i<=n;i++)
		r = (r+1999)%i;
	if(str.at(r) == ' ') cout<<"No"<<endl;
	else if(str.at(r) == '?') cout<<"Yes"<<endl;
	else cout<<"No comments"<<endl;
	return 0;
}