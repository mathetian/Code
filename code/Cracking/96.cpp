#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include <string.h>

bool find(int**matrix, int m,int n,int t)
{
	int r=0,c=n-1;
	while(r<m&&c>=0)
	{
		if(matrix[r][c]==t) return true;
		else if(matrix[r][c]>t) c--;
		else r++;
	}
	return false;
}

int main()
{
	return 0;
}