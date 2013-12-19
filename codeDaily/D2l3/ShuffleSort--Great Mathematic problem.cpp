#include <vector>
#include <string>
using namespace std;

double shuffle(vector<int> const &cards) 
{
	//f(n): shuffle n cards, first shuffle, then judge. Judge again. Then shuffle
	//f(n)=1+(1-t/n)f(n)+(t/n)(f(n-1)-1).....How to get it.
	//f(n)=(n/t)+f(n-1)-1
	vector<int> c=vector<int>(cards.begin(),cards.end());
	sort(c.rbegin(),c.rend());int i=1,j;double r=1;
	while(i<c.size())
	{
		for(j=i-1;j>=0;j--) if(c.at(i)!=c.at(j)) break;
		r=r-1+(i+1)/(double)(i-j);i++;
	}
    return r;
}
