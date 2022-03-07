# project name
PROJECT(Scene)

# using C++11  环境
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -O3 -mtune=native ")

# cmake最低版本
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

# 命令add_subdirectory()，这个命令可以向当前工程添加存放源文件的子目录，并可以指定中间二进制和目标二进制的存放位置，具体用法可以百度。
# 这里指定src目录下存放了源文件，当执行cmake时，就会进入src目录下去找src目录下的CMakeLists.txt，所以在src目录下也建立一个CMakeLists.txt
add_subdirectory(src)
