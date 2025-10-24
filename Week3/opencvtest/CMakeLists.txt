cmake_minimum_required(VERSION 3.10)
project(opencvtest)

# 基础配置
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

# OpenCV
find_package(OpenCV REQUIRED)

# 输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# 精确指定源文件，避免递归搜索构建目录
file(GLOB SOURCES 
    "src/*.cpp"
    "*.cpp"  # 仅根目录，不递归
)

# 精确指定头文件
file(GLOB HEADERS 
    "include/*.h"
    "*.h"    # 仅根目录，不递归
)

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# 包含目录
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${OpenCV_INCLUDE_DIRS}
)

# 链接库
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
