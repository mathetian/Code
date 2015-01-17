#include <iostream>
using namespace std;

#include <assert.h>

#define ASSERT_EQUAL(a,b) assert(a==b)

int addone(int a)
{
	int b=1,c=1;
	
	while((a&c) != 0)
	{ b<<=1;b|=1;c<<=1; }

	a^=b;

	return a;
}

void DoTest()
{
	ASSERT_EQUAL(addone(3),4);
	ASSERT_EQUAL(addone(12),13);
	ASSERT_EQUAL(addone(0),1);
}

int main()
{
	DoTest();
	return 0;
}