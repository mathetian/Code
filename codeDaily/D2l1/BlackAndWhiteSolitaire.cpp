#include <vector>
#include <string>
using namespace std;

int dfs(string cardFront)
{
	int n=cardFront.size();
	char c=cardFront.at(0);
	int m=0;
	for(int i=1;i<n;i++)
	{
		if(i%2==0)
		{
			if(cardFront.at(i)!=c) m++;
		}
		else
		{
			if(cardFront.at(i)==c) m++;
		}
	}
	return m;
}

int minimumTurns(string const &cardFront) {
   	if(cardFront.size()<=1) return 0;
   	string card2=cardFront;
   	int a=dfs(card2);
   	if(card2.at(0)=='B') card2[0]='W';
   	else card2[0]='B';
   	int b=dfs(card2)+1;
   	return min(a,b);
}
