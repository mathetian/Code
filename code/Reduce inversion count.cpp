#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include <stdlib.h>

// inversions = 0
// let count = array of size array.Length
// for i = 0 to array.Length - 1 do
//     for j = array[i] + 1 to maxArrayValue do
//         inversions = inversions + count[j]

//     count[array[i]] = count[array[i]] + 1

int countIn(vector<int>arr)
{
	int n=arr.size(); int count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j]) count++;
		}
	}
	return count;
}

int get(vector<int>arr)
{
	int count=countIn(arr);
	for(int i=0;i<arr.size();i++)
	{
		for(int j=i+1;j<arr.size();j++)
		{
			vector<int>arr2=arr;
			swap(arr2[i],arr2[j]);
			count=min(countIn(arr2),count);
		}
	}
	return count;
}

int main()
{
	string str;
	while(std::getline (std::cin,str))
	{
		vector<int>arr;
		int i=0;
		while(i<str.size())
		{
			int j=i+1;
			for(;j<str.size()&&str.at(j)!=',';j++);
			arr.push_back(atoi(str.substr(i,j-i).c_str()));
			i=j+1;
		}
		cout<<get(arr)<<endl;
	}
	return 0;
}