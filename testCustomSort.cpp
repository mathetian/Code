#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**from our test, we can understand what thing we should tranfser into sort**/
class A{ public: int val; };

bool operator<(const A&a, const A&b)
{
	return a.val < b.val;
}

struct bigfirstcmp
{
    bool operator()(A a,A b){
    	if(a.val < b.val) return 0;
    	return 1;
    }
};

int main()
{
	vector<A>arr;
	for(int i=0;i<10;i++)
	{
		arr.push_back(A());
		arr[i].val = i;
	}
	sort(arr.begin(), arr.end(), bigfirstcmp());

	for(int i=0;i<10;i++)
	{
		cout<<arr.at(i).val<<endl;
	}
	return 0;
}

