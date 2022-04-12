cmake_minimum_required (VERSION 3.22)
#sender和receiver各自需要编制一个CMakeLists.txt
project (Elgamal)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
# 将源代码添加到此项目的可执行文件。
link_directories("/usr/local/lib ../source")
add_executable (test "../test.cpp" "../Elgamal.cpp")

target_link_libraries(test "gmp")
include_directories("/usr/local/include")
#-I
