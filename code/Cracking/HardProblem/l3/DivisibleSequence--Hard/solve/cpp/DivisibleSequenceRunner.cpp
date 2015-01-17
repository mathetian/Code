#include <topcoder>
using namespace TopCoder;
#include "DivisibleSequence.cpp"
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    try {
        ifstream ifs(argv[1]);
        int N; read(ifs, N); next(ifs);
        int H; read(ifs, H);
        ifs.close();

        ofstream ofs(argv[2]);
        show(ofs, count(N, H));
        ofs.close();
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
