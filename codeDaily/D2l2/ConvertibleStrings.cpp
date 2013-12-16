#include <vector>
#include <string>
using namespace std;

//first solution
int leastRemovals(string const &A,
                  string const &B) {
	int count=9;vector<char> cVec;
	for(int i=0;i<9;i++) cVec.push_back('A'+i);
	do{	
		int c=0;
		for(int i=0;i<A.size();i++)	if(A[i]!=cVec.at(B.at(i)-'A'))	c++;
		count=min(count,c);
	}while(next_permutation(cVec.begin(),cVec.end()));
    return count;
}

//second solution
/*int leastRemovals(string const &A,
                  string const &B) {
}*/