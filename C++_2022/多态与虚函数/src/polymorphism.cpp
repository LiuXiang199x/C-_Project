#include "polymorphism.h"

using namespace std;


Shape::Shape(int a, int b){
    width = a;
    height = b;
}

int Shape::area(){
    cout << "Parent class area : 0000 -> (i am in parent class!!)" << endl;
    return 0;
}

// Rectangle::Rectangle(int cc=1, int dd=2):Shape(cc, dd){
// }  
// 这里函数里面其实已经不用再详细写了，因为Shape::Shape里面帮你把内容定义好了

int Rectangle::area(){
    cout << "Rectangle class area : " << width*height << " -> (i am in rectangle class!!)" <<endl;
    return (width * height); 
}


int Triangle::area(){

    cout << "Triangle class area : " << (width * height / 2) << " -> (i am in triangle class!!)" <<endl;

    return (width * height / 2);
}


int test_polymorphism(){
    Shape a(2,2);
    Rectangle b;
    Triangle c;

    cout << "Shape: " << a.area() << endl;
    cout << "Rectangle: " << b.area() << endl;
    cout << "Triangle: " << c.area() << endl;

    return 0;
}