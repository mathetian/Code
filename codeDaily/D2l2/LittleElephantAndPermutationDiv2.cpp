#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int64 getNumber(int N,
                int K) {
    vector<int>values;
    for(int i=1;i<=N;i++) values.push_back(i);
    int64 r1=0;
    do{
    	int r=0;
    	for(int i=1;i<=N;i++) r=r+max(values.at(i-1),i);
    	if(r>=K) r1++; 
    }while(next_permutation(values.begin(),values.end()));
    for(int i=2;i<=N;i++) r1*=i;
    return r1;
}
