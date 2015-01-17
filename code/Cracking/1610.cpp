#include <iostream>
#include <vector>
using namespace std;

int**my2DAlloc(int m,int n)
{	
	int header=m*sizeof(int*);
	int data=m*n*sizeof(int);
	int**ptr=(int**)malloc(header+data);
	int*buf=(int*)(ptr+header);
	for(int i=0;i<m;i++)
		ptr[i]=buf+i*n*sizeof(int);
	return ptr;
}