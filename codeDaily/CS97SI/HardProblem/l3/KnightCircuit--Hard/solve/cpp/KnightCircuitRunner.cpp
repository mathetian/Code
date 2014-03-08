#include <topcoder>
using namespace TopCoder;
#include "KnightCircuit.cpp"
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    try {
        ifstream ifs(argv[1]);
        int w; read(ifs, w); next(ifs);
        int h; read(ifs, h); next(ifs);
        int a; read(ifs, a); next(ifs);
        int b; read(ifs, b);
        ifs.close();

        ofstream ofs(argv[2]);
        show(ofs, maxSize(w, h, a, b));
        ofs.close();
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
