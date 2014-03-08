#include <topcoder>
using namespace TopCoder;
#include "FoxAndSorting.cpp"
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    try {
        ifstream ifs(argv[1]);
        int64 idx; read(ifs, idx);
        ifs.close();

        ofstream ofs(argv[2]);
        show(ofs, get(idx));
        ofs.close();
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
