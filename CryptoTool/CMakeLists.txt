cmake_minimum_required (VERSION 3.10)
project (CryptoTool)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)

# 包含头文件目录
include_directories(include)

# 查找所有源文件
file(GLOB SOURCES "src/*.cpp")

# 添加可执行文件
add_executable(CryptoTool ${SOURCES})

# 设置编译属性
target_compile_features(CryptoTool PRIVATE cxx_std_11)
