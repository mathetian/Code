#include <topcoder>
using namespace TopCoder;
#include "FlippingBitsDiv2.cpp"
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    try {
        ifstream ifs(argv[1]);
        vector<string> S; read(ifs, S); next(ifs);
        int M; read(ifs, M);
        ifs.close();

        ofstream ofs(argv[2]);
        show(ofs, getmin(S, M));
        ofs.close();
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
