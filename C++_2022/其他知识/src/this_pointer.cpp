#include "this_pointer.h"

using namespace std;


void A::hello(){
    cout << "hello world!!!!" << endl;
}


int test_run(){

    A* pstr = new A;
    pstr->hello();

    return 0;
}