#include <topcoder>
using namespace TopCoder;
#include "ThreeColorabilityEasy.cpp"
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    try {
        ifstream ifs(argv[1]);
        vector<string> cells; read(ifs, cells);
        ifs.close();

        ofstream ofs(argv[2]);
        show(ofs, isColorable(cells));
        ofs.close();
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
