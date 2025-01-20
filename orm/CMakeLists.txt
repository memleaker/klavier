cmake_minimum_required(VERSION 3.29)
project(liborm)
set(CMAKE_CXX_STANDARD 20)

include_directories("../thirdlibs/json-3.11.2/include")
include_directories("../thirdlibs/spdlog/include")

if (CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")
    # mysql
    message("current platform: Windows")
    set(MYSQL_INCLUDE_DIR ../thirdlibs/mysql/include)

else()
    # mysql
    message("current platform: Linux")
    set(MYSQL_INCLUDE_DIR /usr/include/mysql)
endif()

include_directories(${MYSQL_INCLUDE_DIR})
aux_source_directory(core DIR_SRC)
add_library(${PROJECT_NAME} ${DIR_SRC})

#target_include_directories(${PROJECT_NAME} PUBLIC
#        .
#        ${MYSQL_INCLUDE_DIR}
#        ../thirdlibs/spdlog/include
#        ../thirdlibs/json-3.11.2/include
#)
