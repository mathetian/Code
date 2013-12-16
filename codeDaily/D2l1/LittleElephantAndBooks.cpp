#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int getNumber(vector<int> const &pages,
              int number) {
   	vector<int>a(pages.begin(),pages.end());
   	sort(a.begin(),a.end());
  // 	cout<<a.size()<<endl;
   	int r=0;
   	for(int i=0;i<number;i++)
   		r+=a.at(i);
   	if(number==a.size()) return r;
   	return r-a.at(number-1)+a.at(number);
}

/*int main()
{
	int r[]={1,2};
	vector<int> pages(r,r+2);
	cout<<getNumber(pages,1)<<endl;
	return 0;
}*/