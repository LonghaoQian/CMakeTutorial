#----------- install static library --------------
include(CMakePackageConfigHelpers)
message(STATUS "env path is " ${ENV})
message(STATUS "CMAKE_INSTALL_PATH: " ${CMAKE_INSTALL_PREFIX})

# ----------- define installation -------------
set(PackageName TestLib)

# define install path

message(STATUS "binary dir: " ${CMAKE_BINARY_DIR})

set(INCLUDE_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/include/)
set(SYSCONFIG_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/etc/${PackageName}/) # not used so far
set(LIBRARY_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/lib/)

include(CMakePackageConfigHelpers)

configure_package_config_file(
    ${CMAKE_SOURCE_DIR}/cmake/${PackageName}Config.cmake.in
    ${CMAKE_BINARY_DIR}/${PackageName}Config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${PackageName}/cmake
    PATH_VARS INCLUDE_INSTALL_DIR LIBRARY_INSTALL_DIR
)

write_basic_package_version_file(
    ${CMAKE_BINARY_DIR}/${PackageName}ConfigVersion.cmake
    VERSION 1.0
    COMPATIBILITY SameMajorVersion
)

# copy the package configuration file to given destination
install(FILES ${CMAKE_BINARY_DIR}/${PackageName}Config.cmake
    ${CMAKE_BINARY_DIR}/${PackageName}ConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${PackageName}/cmake
)

# copy the binary file to lib
install(TARGETS MyLibB
        EXPORT ${PackageName}
        LIBRARY DESTINATION lib
)

#---------- scan all header files of the shared lib
file(GLOB_RECURSE lib_b_header ${CMAKE_SOURCE_DIR}/lib/shared/*.h)
foreach(filename ${lib_b_header})
    message(STATUS "header file is: " ${filename})
endforeach()

# copy the header files to include
install(FILES ${lib_b_header}
        DESTINATION include
)