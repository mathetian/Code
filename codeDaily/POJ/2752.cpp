#include <string>
#include <iostream>
#include <vector>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)
#define FR(i,n) for(i=n-1;i>=0;i--)

vector<int> getnext(string str)
{
	vector<int> next(str.size(), -1);
	int i,j,k; FF(i,str.size())
	{
		for(j=i;j>=1;j--)
		{
			int r = i-j+1; 
			FF(k,j)
			{
				if(str.at(k) != str.at(r+k))
					break;
			}
			if(k == j)
				break;
		}
		if(j>=1) 
			next[i] = j-1;
	}
	return next;
}

vector<int> getnext2(string str)
{
	vector<int> next(str.size(), -1);
	next[0] = -1;
	//next[i] = next^[i-1]+1
	//str[next^[i-1]+1] == str.at(i), next^[i-1] >= 0.
	int i,k;FF(i,str.size())
	{
		if(i==0) continue; k = next[i-1];
		while(k>=0 && str.at(k+1) != str.at(i)) 
			k = next[k];
		
		if(k>=0) next[i] = k+1;
		else if(str.at(0) == str.at(i)) next[i] = 0;
	}
	return next;
}

//P << T
void kmp(string T, string P)
{
	vector<int> next = getnext(P);
	int i, k = -1;  FF(i, T.size())
	{
		while(k>=0 && P.at(k+1) != T.at(i))
			k = next[k];

		if(P.at(k+1) == T.at(i)) k++;
		else k=-1;

		if(k==P.size()-1)
		{
			cout<<T.substr(i-P.size()+1,P.size())<<endl;
			break;
		}
	}
}

vector<int> next1;

void backtraverse(int id)
{
	if(id == -1) return;
	backtraverse(next1[id]);
	cout<<id+1<<" ";
}

int main()
{
	// getnext("ababababca");
	// getnext2("ababababca");
	// kmp("ABCABCDABABCDABCDABDE","ABCDABD");
	string str;
	while(cin>>str)
	{
		next1 = getnext2(str);
		backtraverse(next1.size()-1);
		cout<<endl;
	}
	return 0;
}