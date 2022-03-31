#include "pointer.h"

using namespace std;

int Pointer::simple_max_menos(){

    int a=10, b=20;

    int *p1=&a, *p2;

    p2 = &b;

    cout << " &a=" << &a << " p1=" << p1 << " *p1=" << *p1 << " &p1=" << &p1 << endl;
    cout << " &b=" << &b << " p2=" << p2 << " *p2=" << *p2 << " &p2=" << &p2 << endl;
    // int d = *p1++;  // 10
    // int dd = ++*p1; // 11
    // cout << dd << endl;

    // *p++: 后赋值（内容上操作）；
    // ++*p: 先赋值（内容上操作）;
    // *++p/*(++p): 先加地址（地址上操作）;
    // *(p++): 先*p操作然后再地址++(先值不变*p取出来后再p存放的地址++)；
    // 32位机器，每一位寻址就是一个字节，int占四个字节，所以地址+1就是8c-90. +1 或自增都是移动4位（int类型）

    cout << " *p1++=" << *p1++ << "先赋值*p1再++， *++p1=" << *++p1 << "地址加了一位再取值， ++*p1=" << ++*p1 << \
        "前面地址已经加了一位了，在内容中+1， *(p1++)=" << *(p1++) << endl;
    cout << *p1 << " " << p1 << endl;       // 1140850815 0x7ffee6acd94d
    cout << *(p1--) << " " << p1 << endl;   // 1140850815 0x7ffee6acd949
    cout << *p1 << " " << p1 << endl;       // -18436903  0x7ffee6acd949
    cout << *(++p1) << " " << p1 << endl;   // 1140850815 0x7ffee6acd94d
    cout << *p1 << " " << p1 << endl;       // 1140850815 0x7ffee6acd94d
    cout << *++p1 << " " << p1 << endl;   // 1140850815 0x7ffee6acd94d
    cout << *p1 << " " << p1 << endl;       // 1140850815 0x7ffee6acd94d
    // 重点！！注意上面的dd，++*p1 到了11，cout里面又经过了一次++p1，到这个位置的时候dd已经位12了。
    // cout << dd << endl;   // 12

    int *ppp;
    int ii=2;
    ppp = &ii;
    // 0x7ffeb445be8c 0x7ffeb445be90 0x7ffeb445be8c 0x7ffeb445be90
    // 32位机器，每一位寻址就是一个字节，int占四个字节，所以地址+1就是8c-90.
    // ppp+1 并不是自增，所以看后面可以知道ppp++打印还是原来ppp地址; 若改为++ppp就是打印的自增后的地址
    cout << ppp << " " << ppp+1 << " " << ++ppp << " " << ppp << endl;

    return 0;
}

int array_pointer(){


    return 0;
}