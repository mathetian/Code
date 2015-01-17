/**
	What does it means? 
	Question, https://sites.google.com/site/spaceofjameschen/home/c-1/compute-the-factorial-of-a-large-number

	Solution, http://stackoverflow.com/questions/1966077/calculate-the-factorial-of-an-arbitrarily-large-number-showing-all-the-digits
**/

#include <iostream>
using namespace std;

#include <string.h>

void print(int n)
{
	int arr[100];
	memset(arr, 0, sizeof(arr));
	arr[0]=1; int h=1;
	for(int i=1;i<=n;i++)
	{
		int carry=0;
		for(int j=0;j<h;j++)
		{
			arr[j]=arr[j]*i+carry;
			carry=arr[j]/10;
			arr[j]%=10;
		}
		while(carry!=0)
		{
			arr[h++]=carry%10;
			carry/=10;
		}
	}
	for(int i=h-1;i>=0;i--)
		cout<<arr[i];
	cout<<endl;
}

void DoTest()
{
	print(5);
	print(12);
	print(20);
}

int main()
{
	DoTest();
	cout<<"Passed All Tests"<<endl;
	return 0;
}