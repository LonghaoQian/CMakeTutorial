# list variable
# defining list
set(L0 a b c)
set(L1 a;b;c)
set(L2 "a;b;c")
# empty list
set(L3 "")
# print
message(STATUS "L0 is " ${L0})
message(STATUS "L1 is " ${L1})
message(STATUS "L2 is " ${L2})
message(STATUS "L3 is " ${L3})
# append element
LIST(APPEND L0 d)
LIST(APPEND L3 a d c)
message(STATUS "L0 after append is " ${L0})
message(STATUS "L3 after append is " ${L3})
# remove element
LIST(REMOVE_AT L1 1)
message(STATUS "L1 after remove is " ${L1})
# length of a list
LIST(LENGTH L0 L0_Len)
message(STATUS "length of L0 is " ${L0_Len})
# access elements by index
LIST(GET L0 0 L0_first) # by index
LIST(GET L0 -1 L0_last) # last element
LIST(GET L0 -2 L0_2_last) # second to the last element
message(STATUS "L0 first is " ${L0_first})
message(STATUS "L0 last is " ${L0_last})
message(STATUS "L0 second to the last is " ${L0_2_last})
# find variable in a list
LIST(FIND L0 b find_index) # by index
message(STATUS "L0, b has an index of " ${find_index})
# put multiple strings together
set(L4 ${L1};${L2})
message(STATUS "L4 is " ${L4})
# combine all strings in list to a new string
LIST(JOIN L4 "." L4_str)
message(STATUS "L4_str is " ${L4_str})
# get a sub list
LIST(SUBLIST L0 0 2 L0_substr)
message(STATUS "L0 substr is " ${L0_substr})
# transform of a list
set(L5 ${L4};0;2) # save a copy of L4 to L5
LIST(TRANSFORM L4 APPEND 1 OUTPUT_VARIABLE L4_app1) # witout modifying the original variable
message(STATUS "L4_app1 is " ${L4_app1})
LIST(TRANSFORM L4 APPEND 1) # modify the original variable
message(STATUS "L4 append 1 is: " ${L4})
LIST(TRANSFORM L4 TOUPPER)
message(STATUS "L4 to uppder is: " ${L4})
LIST(TRANSFORM L4 TOLOWER)
message(STATUS "L4 to lower is: " ${L4})
set(L6 " a k k 1 ")
message(STATUS "L6 before STRIP: " ${L6})
LIST(TRANSFORM L6 STRIP OUTPUT_VARIABLE L6_after_strip) # removes the front and the rear space
message(STATUS "L6 after STRIP: " ${L6_after_strip})
LIST(APPEND L6 2)
LIST(APPEND L6_after_strip 2)
message(STATUS "L6 before STRIP: " ${L6})
message(STATUS "L5 after REPLACE: " ${L5})
LIST(TRANSFORM L5 REPLACE "[a-z]" "L" OUTPUT_VARIABLE L5_after_replace)
message(STATUS "L5 after REPLACE: " ${L5_after_replace})
# sort a list alphabetically (lexicographically)
set(L8 4 3 1 a f b kk 2df ADFC 2KD)
LIST(SORT L8)
LIST(JOIN L8 "-" L8_str)
message(STATUS "L8 after sort: " ${L8_str})
#--------------------------------------------------------------------------------------#
# if statement
# numerical comparison
set(VARIABLE 0)
if (${VARIABLE} LESS 1)
endif()
# determine whether a variable is defined
set(VAR "VAR")
if(VAR)
    message(STATUS "VAR is defined, value is " ${VAR})
    # determine whether a string is equal to another one
    if(${VAR} STREQUAL "VAR")
        message(STATUS "VAR is equal to VAR")
    else()
        message(STATUS "VAR is not equal to VAR")
    endif()
else()
    message(STATUS "VAR is not defined!")
endif()
# determine whether a directory exits
function(DetermineValidDirectory dir)
    if(NOT dir)
        message(STATUS "no directories defined!")
        return()
    endif()
    message(STATUS "directory is: " ${dir})
    if(EXISTS ${dir})
        message(STATUS "directory exits!")
    else()
        message(STATUS "directory does not exits!")
    endif()
endfunction()

# empty
DetermineValidDirectory("")
# valid
DetermineValidDirectory(${CMAKE_SOURCE_DIR}/lib)
# invalid
DetermineValidDirectory(${CMAKE_SOURCE_DIR}/lib2)

# for loop
# print list varibale
message("for loop access list with name")
foreach(x IN LISTS L0)
    message(STATUS ${x})
endforeach()
message("for loop access list with derreference")
foreach(x ${L0})
    message(STATUS ${x})
endforeach()
message("for loop access multip lists")
foreach(x IN LISTS L0 L1 L3)
    message(STATUS ${x})
endforeach()
# loop based on a number index
set(COUNTER 0)
set(RANGE1 1 10 2) # start, stop, step
foreach(x RANGE ${RANGE1})
    math(EXPR COUNTER "${COUNTER}+1")
    message(STATUS "counter: " ${COUNTER})
endforeach()

# while loop
set(COUNTER 0)
while(COUNTER LESS "10")
    math(EXPR COUNTER "${COUNTER}+1")
    message(STATUS "counter: " ${COUNTER})
endwhile()