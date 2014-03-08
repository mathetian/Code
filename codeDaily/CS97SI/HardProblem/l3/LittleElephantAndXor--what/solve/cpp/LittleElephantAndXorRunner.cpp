#include <topcoder>
using namespace TopCoder;
#include "LittleElephantAndXor.cpp"
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    try {
        ifstream ifs(argv[1]);
        int A; read(ifs, A); next(ifs);
        int B; read(ifs, B); next(ifs);
        int C; read(ifs, C);
        ifs.close();

        ofstream ofs(argv[2]);
        show(ofs, getNumber(A, B, C));
        ofs.close();
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
