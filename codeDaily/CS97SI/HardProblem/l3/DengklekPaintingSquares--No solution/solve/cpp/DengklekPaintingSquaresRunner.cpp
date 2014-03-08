#include <topcoder>
using namespace TopCoder;
#include "DengklekPaintingSquares.cpp"
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    try {
        ifstream ifs(argv[1]);
        int N; read(ifs, N); next(ifs);
        int M; read(ifs, M);
        ifs.close();

        ofstream ofs(argv[2]);
        show(ofs, numSolutions(N, M));
        ofs.close();
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
