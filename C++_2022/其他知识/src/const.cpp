#include "const.h"

using namespace std;

int getNum(){
    return 100;
}

int test_const(){

    const int MaxNum = 100;
    // MaxNum = 10;  // 会报错：表达式必须是可修改的左值
    int n = 90;
    const int MaxNum1 = getNum();  //运行时初始化
    const int MaxNum2 = n;  //运行时初始化
    const int MaxNum3 = 80;  //编译时初始化
    printf("%d, %d, %d\n", MaxNum1, MaxNum2, MaxNum3);


    return 0;
}

int const_pointer(){

    // const 也可以和指针变量一起使用，这样可以限制指针变量本身，也可以限制指针指向的数据。
    // const 离变量名近就是用来修饰指针变量的，离变量名远就是用来修饰指针指向的数据，
    // 如果近的和远的都有，那么就同时修饰指针变量以及它指向的数据。
    const int* p1;
    int const* p2;

    return 0;
}


int const_funcParams(){



    return 0;
}
