#include <iostream>
using namespace std;

void rotate(int*arr,int w,int h)
{
}

void rotate(int arr[][4],int w)
{
	for(int i=0;i<w/2;i++)
	{
		//arr[i][i]..
		int len=w-2*i;
		for(int j=0;j<len-1;j++)
		{
			//(i,i+j)->(i+j,w-1-i)->(w-1-i,w-1-i-j)->(w-1-i-j,i)->(i,i+j)
			int tmp=arr[w-1-i-j][i];
			arr[w-1-i-j][i]=arr[w-1-i][w-1-i-j];
			arr[w-1-i][w-1-i-j]=arr[i+j][w-1-i];
			arr[i+j][w-1-i]=arr[i][i+j];
			arr[i][i+j]=tmp;
		}
	}
}

void DoTest()
{	
	int arr[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	rotate(arr,4);
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	DoTest();
	cout<<"Passed All Test"<<endl;

	return 0;
}