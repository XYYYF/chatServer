cmake_minimum_required(VERSION 2.8)   # 要求cmake最低的版本号
project(chatServer)   # 定义当前的工程名

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) # 可执行文件输出位置

# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) 库文件输出位置



include_directories(${PROJECT_SOURCE_DIR}/include) # 头文件的搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include/server) # 头文件的搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include/server/db) # 头文件的搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include/server/model) # 头文件的搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include/server/redis) # 头文件的搜索路径
include_directories(${PROJECT_SOURCE_DIR}/thirdparty) # 头文件的搜索路径

# link_directories(${PROJECT_SOURCE_DIR}/lib) 库文件搜索路径


# set(SRC_LIST ./test.cpp)    设置变量，需要编译的文件列表
# aux_source_directory(. SRC_LIST) 把指定目录下的所有文件加入变量

# set(CMAKE_BUILD_TYPE "Debug") 设置debug模式，没有这一行将不能调试设断点

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g) # 设置C++编译选项


# add_executable(test ${SRC_LIST})  # 生成可执行文件

# add_library(xxx SHARED xxx.cpp) 生产库文件，动态库是SHARED，静态库是STATIC

# set_target_properties(xxx PROPERTIES OUTPUT_NAME "new") 修改库的名字

# target_link_libraries(test muduo_net muduo_base pthread)  (test)可执行文件需要依赖的库

add_subdirectory(src) # 加载子目录
