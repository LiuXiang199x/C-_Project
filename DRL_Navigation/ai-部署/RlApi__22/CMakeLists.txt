# PROJECT(RlApi)

# BUILD LIABARY WITH ALL SOURCES FILE 
# add_dir_srcs(RLAPI_SOURCE_LIST ${TOP_LEVEL_SRC_DIR}/otherlibs/RlApi/src ".cpp")
# add_dir_srcs(RLAPI_SOURCE_LIST ${TOP_LEVEL_SRC_DIR}/otherlibs/RlApi/src ".h")

# BUILD LIABARY WITH ALL SOURCES FILE 
ADD_LIBRARY(RlApi SHARED src/rl_api.cpp)
ADD_DEPENDENCIES(RlApi mrpt-slam)
TARGET_LINK_LIBRARIES(RlApi mrpt-slam)

# SET LIBRARY OUTPUT PATH
SET(LIBRARY_OUTPUT_PATH ${LIB_OUT_DIR})
