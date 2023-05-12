set(STATIC_LIB_TARGET MyLibA) # specify the name of the static library
add_library(${STATIC_LIB_TARGET} STATIC "") # define the static library
target_link_libraries(${STATIC_LIB_TARGET} PUBLIC ${LASAN})
target_include_directories(${STATIC_LIB_TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) # append include directories to the library
#if PUBLIC is used, then the targets that depend on this library have access to the specified directory
target_compile_options(${STATIC_LIB_TARGET} PRIVATE ${GNU_FLAGS})

# choose feature for different linking options
if (${LIB_FEATURE} STREQUAL "feature_1")
    # enable feature_1
    message(STATUS "feature_1 is used!")
    add_subdirectory(feature_1)
elseif(${LIB_FEATURE} STREQUAL "feature_2")
    # enable feature_2
    message(STATUS "feature_2 is used!")
    add_subdirectory(feature_2)
else()
    # default
    message(ERROR "invalid feature, use feature_1 as default!")
    add_subdirectory(feature_1)
endif()