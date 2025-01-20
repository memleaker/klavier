cmake_minimum_required(VERSION 3.29)
project(klavier)
set(CMAKE_CXX_STANDARD 20)

# json 和 orm
add_subdirectory(thirdlibs/json-3.11.2)
add_subdirectory(orm)

# INCLUDE DIR
include_directories("thirdlibs/json-3.11.2/include")
include_directories("thirdlibs/spdlog/include")

if (CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")
    # mysql
    message("current platform: Windows")

    # boost
    include_directories("D:/BOOST/boost_1_87_0/")
    link_directories("D:/BOOST/boost_1_87_0/stage/lib/")

    # Windows
    link_libraries("-lwsock32 -lws2_32")

else()
    # mysql
    message("current platform: Linux")
endif()

# EXE
add_executable(klavier main.cpp)
