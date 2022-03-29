#include "<<_>>write2file.h"
#include "PCres.h"

using namespace std;


int main() {

    everest::ai::PCrest qq;
    cout << qq.pics_url[0] << endl;
    cout << qq.pics_url[1] << endl;
    for(int i=0; i<2; i++){
        cout << qq.nano_res[0][i] << " ";
        cout << qq.nano_res[1][i] << " ";
    }
    cout << endl;
    return 0;
}
