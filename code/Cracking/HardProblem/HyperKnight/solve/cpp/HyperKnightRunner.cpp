#include <topcoder>
using namespace TopCoder;
#include "HyperKnight.cpp"
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    try {
        ifstream ifs(argv[1]);
        int a; read(ifs, a); next(ifs);
        int b; read(ifs, b); next(ifs);
        int numRows; read(ifs, numRows); next(ifs);
        int numColumns; read(ifs, numColumns); next(ifs);
        int k; read(ifs, k);
        ifs.close();

        ofstream ofs(argv[2]);
        show(ofs, countCells(a, b, numRows, numColumns, k));
        ofs.close();
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
