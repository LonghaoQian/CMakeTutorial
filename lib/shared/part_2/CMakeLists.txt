target_include_directories(${SHARED_LIB_TARGET}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

#set(part2_src_list
#    ${CMAKE_CURRENT_SOURCE_DIR}/test_lib_b2.cpp
#    ${CMAKE_CURRENT_SOURCE_DIR}/test_lib_b3.cpp
#)

# auto scan all the source files within the current directory
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} part2_src_list)

target_sources(${SHARED_LIB_TARGET} PRIVATE ${part2_src_list})