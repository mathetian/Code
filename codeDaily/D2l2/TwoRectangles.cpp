#include <vector>
#include <string>
using namespace std;

string describeIntersection(vector<int> const &A,
                            vector<int> const &B) {
    vector<int> A1=A, B1=B;
    if(A.at(1)>B.at(1))
    {
    	A1=B;B1=A;
    }
    //none
    if(B1.at(1)>A1.at(3)) return "none";
    if(B1.at(1)==A1.at(3))
    {
    	if(B1.at(0)>A1.at(2)) return "none";
    	if(B1.at(2)<A1.at(0)) return "none";
    	else if(B1.at(0)==A1.at(2)||B1.at(2)==A1.at(0)) return "point";
    	else return "segment";
    }
    else
    {
    	if(B1.at(0)>A1.at(2)) return "none";
    	if(B1.at(2)<A1.at(0)) return "none";
    	else if(B1.at(0)==A1.at(2)||B1.at(2)==A1.at(0)) return "segment";
    	else return "rectangle";
    }
    return "none";
}
