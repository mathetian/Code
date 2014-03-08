#include <topcoder>
using namespace TopCoder;
#include "MuddyRoad2.cpp"
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    try {
        ifstream ifs(argv[1]);
        int N; read(ifs, N); next(ifs);
        int muddyCount; read(ifs, muddyCount);
        ifs.close();

        ofstream ofs(argv[2]);
        show(ofs, theCount(N, muddyCount));
        ofs.close();
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
