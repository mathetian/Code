#include <iostream>
using namespace std;

/**
	D(n) = 3*D(n-2) + 2*(D(n-4) + D(n-6) ... + D(0)
	D(4) = D(2) +           
**/

int D[31];

int main()
{
	int n,i,j; D[0] = 1;
	for(i = 1;i < 31;i++)
	{
		D[i] = 0;
		if(i % 2 == 0)
		{
			D[i] = 3 * D[i - 2];
			for(j = i-4;j >= 0; j -= 2)
				D[i] += 2 * D[j];
		}
	}

	while(cin >> n)
	{
		if(n == -1) break;
		cout<<D[n]<<endl;
	}
	return 0;
}