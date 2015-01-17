#include <iostream>
#include <vector>
using namespace std;

int gen5()
{

}

int gen7()
{
	int i;
	do{i=5*(gen5()-1)+gen5();}while(i>21);
	return i%7+1;
}