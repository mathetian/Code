#include <iostream>
#include <vector>
using namespace std;

#include <stdlib.h>

int getrand(int m)
{
	return rand()%(m+1);
}

vector<int> pickMRandomly(vector<int>arr,int m)
{
	vector<int> rs(m,0);
	for(int i=0;i<m;i++)
	{
		int id=getrand(m-i);
		rs[i]=arr[id];
		arr[id]=arr[m-i-1];
	}
	return rs;
}