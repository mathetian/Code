#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

/**
	Easy solution, but hard to understand why?
**/

#define FF(i,n) for(i=0;i<n;i++)
#define FFS(i,a,b) for(i=a;i<b;i++)

vector<double> getExpectedPositions(vector<string> const &words) 
{
	vector<double>rs(words.size(),0.0);
	int n=words.size(),m=words.at(0).size(),i,j,k;FF(i,n)
	{
		FFS(j,i+1,n)
		{
			int a=0,b=0;
			FF(k,m)
			{
				if(words[i][k]<words[j][k]) a++;
				else if(words[i][k]>words[j][k]) b++;
			}
			rs[i]=rs[i]+b/(double)(a+b);
			rs[j]=rs[j]+a/(double)(a+b);
		}
	}
    return rs;
}

/*int main()
{
	string aaa[]={"v", "d", "z", "t", "o", "i", "m", "x", "b", "u", "p", "w", "n", "y", "k", "h", "c", "l", "a", "j", "f", "s", "r", "g", "e", "q"};
	vector<string> words(aaa,aaa+sizeof(aaa)/sizeof(string));
	sort(words.begin(),words.end());
	vector<double> rs=getExpectedPositions(words);
	sort(words.begin(),words.end());
	for(int i=0;i<words.size();i++)
		cout<<words.at(i)<<" ";
	cout<<endl;
	for(int i=0;i<rs.size();i++)
		cout<<rs.at(i)<<" ";
	cout<<endl;
	return 0;
}*/