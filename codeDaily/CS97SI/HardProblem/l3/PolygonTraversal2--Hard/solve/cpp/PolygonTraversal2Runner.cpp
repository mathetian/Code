#include <topcoder>
using namespace TopCoder;
#include "PolygonTraversal2.cpp"
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    try {
        ifstream ifs(argv[1]);
        int N; read(ifs, N); next(ifs);
        vector<int> points; read(ifs, points);
        ifs.close();

        ofstream ofs(argv[2]);
        show(ofs, count(N, points));
        ofs.close();
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
