#include <topcoder>
using namespace TopCoder;
#include "FoxAndMountain.cpp"
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    try {
        ifstream ifs(argv[1]);
        int n; read(ifs, n); next(ifs);
        string history; read(ifs, history);
        ifs.close();

        ofstream ofs(argv[2]);
        show(ofs, count(n, history));
        ofs.close();
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
