target_include_directories(${SHARED_LIB_TARGET}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(part1_src_list
    ${CMAKE_CURRENT_SOURCE_DIR}/test_lib_b1.cpp
)

target_sources(${SHARED_LIB_TARGET} PRIVATE ${part1_src_list})