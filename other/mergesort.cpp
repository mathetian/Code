#include <iostream>
#include <vector>
using namespace std;

#define FF(i, n) for(i = 0;i < n;i++)
#define FS(i, a, b) for(i = a; i < b;i++)
#define FR(i, a, b) for(i = a; i >= b;i--)

void mergeDirect(int * arr, int l, int r)
{
	int i, j;
	FS(i, l+1, r+1)
	{
		int tmp = arr[i];
		FR(j, i-1, l)
		{
			if(arr[j] > tmp) arr[j+1] = tmp;
			else break;
		}
		arr[j+1] = tmp;
	}
}

void merge(int * arr, int l, int r)
{
	int m = (l+r)/2;
	vector<int>rs(r-l+1, 0);

	int i = l, j = m + 1, k = 0;
	while(i <= m && j <= r)
		rs[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
	while(i <= m) rs[k++] = arr[i++];
	while(j <= r) rs[k++] = arr[j++];

	for(k = l;k <= r;k++)
		arr[k] = rs[k-l];
}

void mergesort(int * arr, int l, int r)
{
	if(r - l <= 10) mergeDirect(arr,l,r);
	else
	{
		int m = (l+r)/2;
		mergesort(arr, l, m);
		mergesort(arr, m, r);
		merge(arr,l,r);
	}
}

int main()
{
	return 0;
}