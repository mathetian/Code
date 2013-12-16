#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
 
int calculate(vector <int> seq) {
  int n=seq.size(),c=1;
  for(int i=1;i<n;i++)
      if(seq[i-1]>=seq[i])
          c++;
  return c;
}