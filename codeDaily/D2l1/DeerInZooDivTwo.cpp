#include <vector>
#include <string>
using namespace std;

vector<int> getminmax(int N,
                      int K) {
    vector<int> rs;
    int c=2*N-K;
    if(c>=N) rs.push_back(c-N);
    else rs.push_back(0);
    rs.push_back(c/2);
    return rs;
}
