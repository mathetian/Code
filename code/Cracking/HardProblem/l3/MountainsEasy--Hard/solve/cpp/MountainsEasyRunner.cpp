#include <topcoder>
using namespace TopCoder;
#include "MountainsEasy.cpp"
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    try {
        ifstream ifs(argv[1]);
        vector<string> picture; read(ifs, picture); next(ifs);
        int N; read(ifs, N);
        ifs.close();

        ofstream ofs(argv[2]);
        show(ofs, countPlacements(picture, N));
        ofs.close();
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
