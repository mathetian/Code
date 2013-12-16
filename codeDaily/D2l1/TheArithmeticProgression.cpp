#include <vector>
#include <string>
#include <math.h>
using namespace std;

double minimumChange(int a,
                     int b,
                     int c) {
	return abs(2*b-c-a)/2.0;
}
