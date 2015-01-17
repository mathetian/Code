#include <iostream>
#include <vector>
using namespace std;

int numZeros(int num)
{
	int count=0;
	if(num<0) return 0;
	for(int i=5;num/i>=1;i*=5)
		count+=num/i;
	return count;
}