
# FIND_PACKAGE(<name> [major.minor] [QUIET] [NO_MODULE] [[REQUIRED|COMPONENTS] [componets...]])
# 只找一个名为name的包（后面都是修饰条件），所以如果要找多个包，要分多个FIND_PACKAGE()写。
# 当它找到OpenCV程序库之后，就会帮助我们预定义几个变量：
    # OpenCV_FOUND、OpenCV_INCLUDE_DIRS、OpenCV_LIBRARY_DIRS、OpenCV_LIBRARIES，
    # 它们分别指是否找到OpenCV，OpenCV的头文件目录，OpenCV的库文件目录，OpenCV的所有库文件列表。
# 我们后面需要用到OpenCV_INCLUDE_DIRS、OpenCV_LIBRARY_DIRS，不写它这几个变量就无效，所以它必不可少。
# find OpenCV
FIND_PACKAGE(OpenCV REQUIRED)

# show the message of OpenCV
message(STATUS "OpenCV library status:")
message(STATUS "    version: 	${OpenCV_VERSION}")
message(STATUS "    headers: 	${OpenCV_INCLUDE_DIRS}")
message(STATUS "    libraries: 	${OpenCV_LIBS}")

# link headers 链接头文件
INCLUDE_DIRECTORIES({OpenCV_INCLUDE_DIRS})
include_directories (../include)

# set (SRC_LIST main.cpp)
# 添加源代码文件到SRC_LIST变量中
AUX_SOURCE_DIRECTORY(. SRC_LIST)

# 这里又出现一个新的命令set，是用于定义变量的，EXECUTABLE_OUT_PATH和PROJECT_SOURCE_DIR是CMake自带的预定义变量，其意义如下，
# EXECUTABLE_OUTPUT_PATH ：目标二进制可执行文件的存放位置
# PROJECT_SOURCE_DIR：工程的根目录
# 所以，这里set的意思是把存放elf文件的位置设置为工程根目录下的bin目录。（cmake有很多预定义变量，详细的可以网上搜索一下）

# add_library(includeT test SHARED ${SRC})

# 生成可执行文件
add_executable (test_eigen ${SRC_LIST})

# after ADD_EXECUTABLE，为生成文件target添加库，这个必须写在ADD_EXECUTABLE()之后，为生成文件target添加库。
# TARGET_LINK_LIBRARIES(target library1 <debug | optimized> library2...)
TARGET_LINK_LIBRARIES(test_eigen ${OpenCV_LIBS})

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
