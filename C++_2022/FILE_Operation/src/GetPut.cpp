#include "GetPut.h"

using namespace std;

int test_put(){

    char c;
    int a[4] = {1,2,3,4};
    ofstream outFile("../files/GetPut.txt", ios::out);

    if(!outFile){
        cout << "error opening" << endl;
        return 0;
    }

    // while(cin >> c){
    //     // c 有多长，while就会iu循环几次
    //     cout << "loading char to file" << endl;
    //     outFile.put(c);
    // }

    for(int i=0; i<4; i++){
        char x = "0" + a[i];
        outFile.put(x);
    }
    outFile.close();

    return 0;
}

int test_get(){

    return 0;
}