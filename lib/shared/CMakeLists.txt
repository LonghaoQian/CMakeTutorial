set(SHARED_LIB_TARGET MyLibB)
add_library(${SHARED_LIB_TARGET} SHARED "") # no source specified at this time
target_link_libraries(${SHARED_LIB_TARGET} PUBLIC ${LASAN})
target_include_directories(${SHARED_LIB_TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(${SHARED_LIB_TARGET} PRIVATE ${GNU_FLAGS})
# organize all 
add_subdirectory(part_1)
add_subdirectory(part_2)
add_subdirectory(part_3)