#include <topcoder>
using namespace TopCoder;
#include "BallsSeparating.cpp"
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    try {
        ifstream ifs(argv[1]);
        vector<int> red; read(ifs, red); next(ifs);
        vector<int> green; read(ifs, green); next(ifs);
        vector<int> blue; read(ifs, blue);
        ifs.close();

        ofstream ofs(argv[2]);
        show(ofs, minOperations(red, green, blue));
        ofs.close();
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
