#include <topcoder>
using namespace TopCoder;
#include "SurveillanceSystem.cpp"
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    try {
        ifstream ifs(argv[1]);
        string containers; read(ifs, containers); next(ifs);
        vector<int> reports; read(ifs, reports); next(ifs);
        int L; read(ifs, L);
        ifs.close();
        cout<<argv[1]<<endl;
        ofstream ofs(argv[2]);
        show(ofs, getContainerInfo(containers, reports, L));
        ofs.close();
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
