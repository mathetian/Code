#include <topcoder>
using namespace TopCoder;
#include "FoxPaintingBalls.cpp"
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    try {
        ifstream ifs(argv[1]);
        int64 R; read(ifs, R); next(ifs);
        int64 G; read(ifs, G); next(ifs);
        int64 B; read(ifs, B); next(ifs);
        int N; read(ifs, N);
        ifs.close();

        ofstream ofs(argv[2]);
        show(ofs, theMax(R, G, B, N));
        ofs.close();
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
