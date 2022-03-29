#ifndef _ReadWriteBinaryFile_H_
#define _ReadWriteBinaryFile_H_
#include <iostream>

class CStudent
{
    char szName[20];  //假设学生姓名不超过19个字符，以 '\0' 结尾
    // char szId[0];  //假设学号为9位，以 '\0' 结尾
    int age;  //年龄
};

#endif // !_ReadWriteBinaryFile_H_