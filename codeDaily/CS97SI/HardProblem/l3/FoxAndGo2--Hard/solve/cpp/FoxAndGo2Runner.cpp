#include <topcoder>
using namespace TopCoder;
#include "FoxAndGo2.cpp"
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    try {
        ifstream ifs(argv[1]);
        vector<string> board; read(ifs, board);
        ifs.close();

        ofstream ofs(argv[2]);
        show(ofs, maxKill(board));
        ofs.close();
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
