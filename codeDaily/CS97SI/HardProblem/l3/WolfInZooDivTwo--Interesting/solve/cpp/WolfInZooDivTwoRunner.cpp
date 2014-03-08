#include <topcoder>
using namespace TopCoder;
#include "WolfInZooDivTwo.cpp"
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    try {
        ifstream ifs(argv[1]);
        int N; read(ifs, N); next(ifs);
        vector<string> L; read(ifs, L); next(ifs);
        vector<string> R; read(ifs, R);
        ifs.close();

        ofstream ofs(argv[2]);
        show(ofs, count(N, L, R));
        ofs.close();
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
