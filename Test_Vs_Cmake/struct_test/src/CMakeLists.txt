FIND_PACKAGE(OpenCV REQUIRED)

INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS} ../include)

SET(SRC_LIST main.cpp)

add_executable (test ${SRC_LIST})

# after ADD_EXECUTABLE，为生成文件target添加库，这个必须写在ADD_EXECUTABLE()之后，为生成文件target添加库。
# TARGET_LINK_LIBRARIES(target library1 <debug | optimized> library2...)
target_link_libraries(test ${OpenCV_LIBS})

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)