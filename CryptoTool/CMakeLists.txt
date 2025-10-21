cmake_minimum_required (VERSION 3.10)
project (CryptoTool)

set(CMAKE_CXX_STANDARD 11)
# 必须使用C++编译
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置输出目录
# 可执行文件输出
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
# 静态库输出目录（本次没用）
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)
# 动态库输出目录（本次没用）
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)

# 包含头文件目录
include_directories(include)

# 查找所有源文件
file(GLOB SOURCES "src/*.cpp")

# 添加可执行文件
add_executable(CryptoTool ${SOURCES})

# 设置编译属性（仅对该目标生效）
target_compile_features(CryptoTool PRIVATE cxx_std_11)
