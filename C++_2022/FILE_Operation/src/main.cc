#include <iostream>
#include <fstream>
using namespace std;
int main() {
    const char *strrr = "wo hao shuai a !!!!!!!";
    //创建一个 fstream 类对象
    fstream fs;
    //将 test.txt 文件和 fs 文件流关联
    fs.open("/home/marco/C-_Project/C++_2022/FILE_Operation/files/test2.txt", ios::out);
    //向test.txt文件中写入 url 字符串
    fs.write(strrr, 10);
    fs.close();
    return 0;
}