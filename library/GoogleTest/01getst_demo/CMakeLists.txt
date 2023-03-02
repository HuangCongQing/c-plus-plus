cmake_minimum_required(VERSION 3.1)

project(getst_demo)

set(CMAKE_CXX_STANDARD 14)


# 包含头文件
include_directories(./include DIR_INC)

# 添加路径（为了下面静态文件.a 少些lib/）
link_directories(./lib) # 

add_executable(main src/main.cpp)
target_link_libraries(main libgtest.a libgtest_main.a libgmock.a libgmock_main.a pthread) # 链接gtest库  Tips: pthread is must 

# GTest 依赖 pthread 库, 所以要链接.
# 特别提示: pthread 库一定要写在 ${GTEST_BOTH_LIBRARIES}