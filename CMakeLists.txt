cmake_minimum_required(VERSION 3.15)
project(cmake_tutorial VERSION 1.0.0 LANGUAGES C CXX)
#------------------ set compile options----------------#
set(CMAKE_CXX_STANDARD 17)

# display build type
message("-- build type is set to " ${CMAKE_BUILD_TYPE})

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    message("build type is debug")
    set(GNU_FLAGS "-Wall;-Werror;-Wextra;-O0;-g;-fno-omit-frame-pointer;-fsanitize=address")
    set(LASAN -lasan)
else()
    message("build type is release")
    set(GNU_FLAGS "-O3")
    set(LASAN "") # no lasan lib is add in release mode
endif()
#--------------- build target --------------------------
add_executable(test1 src/test1.cpp)
target_link_libraries(test1 PUBLIC ${LASAN})
target_compile_options(test1 PUBLIC ${GNU_FLAGS})

add_executable(test2 src/test2.cpp)
target_link_libraries(test2 PUBLIC ${LASAN})
target_compile_options(test2 PUBLIC ${GNU_FLAGS})

add_executable(test3 src/test3.cpp)
target_link_libraries(test3 PUBLIC ${LASAN})
target_compile_options(test3 PUBLIC ${GNU_FLAGS})

add_executable(test4 src/test4.cpp)
target_link_libraries(test4 PUBLIC ${LASAN})
target_compile_options(test4 PUBLIC ${GNU_FLAGS})