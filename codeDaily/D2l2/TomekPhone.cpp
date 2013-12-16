#include <vector>
#include <string>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)
#define SR(c) {sort(c.begin(),c.end());reverse(c.begin(),c.end());}

int minKeystrokes(vector<int> const &frequencies,
                  vector<int> const &keySizes) {
    int a=0;int i;
    FF(i,keySizes.size()) a+=keySizes.at(i);
    if(a<frequencies.size()) return -1;
    int m=frequencies.size(),n=keySizes.size();
    vector<int> used;int most=0;int index=-1;
    FF(i,n) used.push_back(0);
    vector<int> fr=frequencies;SR(fr);

    FF(i,m)
    {
    	int oi=index;index=(index+1)%n;
    	while(index!=oi&&used.at(index)>=keySizes.at(index)) index=(index+1)%n;
		used[index]++;
		most+=used[index]*fr.at(i);
    }
    return most;
}
