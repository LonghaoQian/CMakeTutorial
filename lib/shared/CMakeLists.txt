set(SHARED_LIB_TARGET MyLibB) # specify the name of the static library
set(lib_b_src ${CMAKE_CURRENT_SOURCE_DIR}/test_lib_b.cpp) # specify a list of source files
add_library(${SHARED_LIB_TARGET} SHARED ${lib_b_src}) # define the static library
target_link_libraries(${SHARED_LIB_TARGET} PUBLIC ${LASAN})
target_include_directories(${SHARED_LIB_TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) # append include directories to the library
#if PUBLIC is used, then the targets that depend on this library have access to the specified directory
target_compile_options(${SHARED_LIB_TARGET} PRIVATE ${GNU_FLAGS})