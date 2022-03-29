#include "PCres.h"

using namespace std;
using namespace everest::ai;

PCrest::PCrest(){
    cout << "Start init params =======>>>>>> " << endl;
    init_Params();
    nano_res[1][0] = 111;
    nano_res[1][1] = 222;
}

PCrest::~PCrest(){}

void PCrest::init_Params(){
    cout << "im in init_Params" << endl;
    // nano_res[2][2] = {1, 2, 3, 4};     // 该方法不行
    // nano_res[2][2] << 1, 2, 3, 4;      // 该方法不行
    nano_res[0][0] = 1;
    nano_res[0][1] = 2;

    pics_url[0] = "123";
    pics_url[1] = "222";
}