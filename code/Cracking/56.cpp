#include <string>
#include <iostream>
using namespace std;

int swapOddEvenBits(int a)
{
	return (((a&(0xaaaaaaaa))>>1)|((a&(0x55555555))>>1));
}