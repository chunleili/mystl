cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 17)
project(mystl)


# 制作一个伪目标stlLib 把所有头文件都传给它, 只要link这个lib即可将所有头文件导入
file(GLOB allSrc src/mystl/*)
add_library(stlLib INTERFACE ${allSrc})
target_include_directories(stlLib INTERFACE src)

enable_testing()
# 简单地增加测试
function(addtest testname)
    add_executable(test_${testname} tests/test_${testname}.cpp)
    target_include_directories(test_${testname} PRIVATE src)
    add_test(NAME test_${testname} COMMAND test_${testname})
endfunction(addtest)

addtest(catch)
addtest(vector)