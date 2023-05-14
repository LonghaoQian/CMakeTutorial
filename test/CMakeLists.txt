aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} src_list)
set(LIB_LIST ${LASAN} MyLibB)
AddTestTarget(src_list LIB_LIST GNU_FLAGS)