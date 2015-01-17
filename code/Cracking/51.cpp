#include <iostream>
using namespace std;

int change(int m,int n,int i,int j)
{
	int r=m&((1<<i)-1);
	r |= (n<<i);
	m &= (~((1<<j)-1));
	r |= m;
	return r;
}

int main()
{
	return 0;
}