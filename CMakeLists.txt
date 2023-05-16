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

#-------- options -----------
option(MAIN_FEATURE_1_CONTROL "main feature 1" ON)

if(${MAIN_FEATURE_1_CONTROL} STREQUAL "ON")
    add_definitions(-DMAIN_FEATURE_1)
endif()
set(LIB_FEATURE "feature_2")

#--------macro defintions
add_definitions(-DMAIN_FEATURE_2)

add_subdirectory(lib)
add_subdirectory(cmake_cmds)

#----- add a path to the module 
message(STATUS "cmake prefix path: "  ${CMAKE_PREFIX_PATH})

#--------------- build target --------------------------
add_executable(test1 src/test1.cpp)
target_link_libraries(test1 PUBLIC ${LASAN})
target_compile_options(test1 PUBLIC ${GNU_FLAGS})

add_executable(test2 src/test2.cpp)
target_link_libraries(test2 PUBLIC ${LASAN})
target_compile_options(test2 PUBLIC ${GNU_FLAGS})

add_executable(test3 src/test3.cpp)
target_link_libraries(test3 PUBLIC ${LASAN} MyLibA)
target_compile_options(test3 PUBLIC ${GNU_FLAGS})

add_executable(test4 src/test4.cpp)
target_link_libraries(test4 PUBLIC ${LASAN})
target_compile_options(test4 PUBLIC ${GNU_FLAGS})

add_executable(test5 src/test5.cpp)
target_link_libraries(test5 PUBLIC ${LASAN} MyLibB MyLibC)
target_compile_options(test5 PUBLIC ${GNU_FLAGS})

add_executable(test6 src/test6.cpp)
target_link_libraries(test6 PUBLIC ${LASAN} MyLibA)
target_compile_options(test6 PUBLIC ${GNU_FLAGS})

#----- access global variable ----
message(STATUS "Var2 is " ${VAR2})

#----------
file(GLOB_RECURSE lib_b_header ${CMAKE_CURRENT_SOURCE_DIR}/lib/shared/*.h)
foreach(filename ${lib_b_header})
    message(STATUS "header file is: " ${filename})
endforeach()

#-------- Add a path to the cmake module -------
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(utils)
add_subdirectory(test)

#----------- install static library --------------
include(CMakePackageConfigHelpers)
message(STATUS "env path is " ${ENV})
message(STATUS "CMAKE_INSTALL_PATH: " ${CMAKE_INSTALL_PREFIX})

# ----------- define installation -------------
set(PackageName TestLib)

# define install path

message(STATUS "binary dir: " ${CMAKE_CURRENT_BINARY_DIR})

set(INCLUDE_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/include/)
set(SYSCONFIG_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/etc/${PackageName}/)
set(LIBRARY_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/lib/)

include(CMakePackageConfigHelpers)

configure_package_config_file(
    cmake/${PackageName}Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PackageName}Config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${PackageName}/cmake
    PATH_VARS INCLUDE_INSTALL_DIR SYSCONFIG_INSTALL_DIR LIBRARY_INSTALL_DIR
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${PackageName}ConfigVersion.cmake
    VERSION 1.0
    COMPATIBILITY SameMajorVersion
)

# copy the package configuration file to given destination
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PackageName}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${PackageName}ConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${PackageName}/cmake
#    PERMISSIONS WORLD_READ WORLD_WRITE
)

# copy the binary file to lib
install(TARGETS MyLibB
        EXPORT ${PackageName}
        LIBRARY DESTINATION lib
#        PERMISSIONS WORLD_READ WORLD_WRITE
)

# copy the header files to include
install(FILES ${lib_b_header}
        DESTINATION include
        PERMISSIONS WORLD_READ WORLD_WRITE
)

#message(STATUS "include install dir: " ${INCLUDE_INSTALL_DIR})
#message(STATUS "system config install dir: " ${SYSCONFIG_INSTALL_DIR})

#write_basic_package_version_file(
#    ${CMAKE_CURRENT_BINARY_DIR}/${PackageName}ConfigVersion.cmake
#    VERSION 1.2.3
#    COMPATIBILITY SameMajorVersion )
# set the name of the library
#install(TARGETS ${PackageName}
#        EXPORT MyLibB
#        LIBRARY DESTINATION lib # LIBRARY for dynamic library
#FILES # copy all the files to the destination
#    ${CMAKE_CURRENT_BINARY_DIR}/${PackageName}Config.cmake
#    ${CMAKE_CURRENT_BINARY_DIR}/${PackageName}ConfigVersion.cmake
#    ${lib_b_header} # copy all the header files to destination
#    DESTINATION ${dest}
#)