set(STATIC_LIB_TARGET MyLibA) # specify the name of the static library
set(lib_a_src ${CMAKE_CURRENT_SOURCE_DIR}/test_lib_a.cpp) # specify a list of source files
add_library(${STATIC_LIB_TARGET} STATIC ${lib_a_src}) # define the static library
target_link_libraries(${STATIC_LIB_TARGET} PUBLIC ${LASAN})
target_include_directories(${STATIC_LIB_TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) # append include directories to the library
#if PUBLIC is used, then the targets that depend on this library have access to the specified directory
target_compile_options(${STATIC_LIB_TARGET} PRIVATE ${GNU_FLAGS})