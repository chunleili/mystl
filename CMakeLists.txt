cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(mystl)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")


# 制作一个伪目标stlLib 把所有头文件都传给它, 只要link这个lib即可将所有头文件导入
file(GLOB allSrc src/mystl/*)
add_library(stlLib INTERFACE ${allSrc})
target_include_directories(stlLib INTERFACE src)


# 简单地增加测试
option(ENABLE_TEST "enable the test" ON)
if(ENABLE_TEST)
  enable_testing()

  function(addtest testname)
      add_executable(test_${testname} tests/test_${testname}.cpp)
      target_include_directories(test_${testname} PRIVATE src)
      add_test(NAME test_${testname} COMMAND test_${testname})
  endfunction(addtest)

  addtest(catch)
  addtest(vector)
endif(ENABLE_TEST)


# 安装到/usr/local/include中
option(ENABLE_INSTALL "enable the install" ON)
if(ENABLE_INSTALL)
  # set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_LIST_DIR}/install)
  message("Installing dir: ${CMAKE_INSTALL_PREFIX}")
  set_target_properties(stlLib PROPERTIES PUBLIC_HEADER ${allSrc})
  include(GNUInstallDirs)
  install(TARGETS stlLib
          PUBLIC_HEADER
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/mystl)
endif(ENABLE_INSTALL)