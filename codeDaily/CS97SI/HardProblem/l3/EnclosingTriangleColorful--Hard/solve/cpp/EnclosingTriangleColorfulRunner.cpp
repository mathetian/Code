#include <topcoder>
using namespace TopCoder;
#include "EnclosingTriangleColorful.cpp"
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    try {
        ifstream ifs(argv[1]);
        int m; read(ifs, m); next(ifs);
        vector<int> x; read(ifs, x); next(ifs);
        vector<int> y; read(ifs, y);
        ifs.close();

        ofstream ofs(argv[2]);
        show(ofs, getNumber(m, x, y));
        ofs.close();
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
