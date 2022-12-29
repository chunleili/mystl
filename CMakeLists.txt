cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(mystl)

# 指定默认的build type, 对VS和ninja这类多配置构建器无用
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")


# 制作一个伪目标stlLib 把所有头文件都传给它, 只要link这个lib即可将所有头文件导入
file(GLOB allSrc src/mystl/*)
add_library(stlLib INTERFACE ${allSrc})
target_include_directories(stlLib INTERFACE src)

# 只是个方便调试的函数
function(echo name)
  message("${name}: ${${name}}")
endfunction(echo)


# 简单地增加测试, 测试框架用catch2, 由于header-only因此无需任何配置
option(ENABLE_TEST "enable the test" ON)
if(ENABLE_TEST)
  enable_testing()
  # 方便增加测试用例的函数，只要用addtest(name)即可
  function(addtest testname)
      add_executable(test_${testname} tests/test_${testname}.cpp)
      target_include_directories(test_${testname} PRIVATE src)
      add_test(NAME test_${testname} COMMAND test_${testname})
  endfunction(addtest)

  #在这里增加测试
  addtest(catch)
  addtest(vector)
  addtest(vec3)
  addtest(quat)
endif(ENABLE_TEST)


# 安装到/usr/local/include中（其实就是把src下面的hpp复制）
option(ENABLE_INSTALL "enable the install" OFF)
if(ENABLE_INSTALL)
  # set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_LIST_DIR}/install)
  message("Installing dir: ${CMAKE_INSTALL_PREFIX}")
  set_target_properties(stlLib PROPERTIES PUBLIC_HEADER ${allSrc})
  include(GNUInstallDirs)
  install(TARGETS stlLib
          PUBLIC_HEADER
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/mystl)
endif(ENABLE_INSTALL)