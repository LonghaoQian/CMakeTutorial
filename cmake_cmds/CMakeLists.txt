# set a variable and print
set(VAR1 "hello")
message(STATUS "VAR1 is " ${VAR1})
# to be modified by the child
add_subdirectory(cmd1)
message(STATUS "VAR1 is " ${VAR1})
message(STATUS "VAR3 is " ${VAR3})


# scope of var1

# define a global variable var2
# set(VAR2 "hello global var2")
set(VAR2 "hello global dd" CACHE STRING "hellow_support" )
message(STATUS "cmake_cmd Var2 " ${VAR2})

message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS ${PROJECT_SOURCE_DIR})
message(STATUS ${CMAKE_BUILD_TYPE})
message(STATUS ${CMAKE_CURRENT_LIST_DIR})
message(STATUS ${CMAKE_SOURCE_DIR})

include(../cmake/utils.cmake)

# changed by -DVAR2=hello_world_2 in as cmake flags

set(FOO_VAR_PARENT "var parent")
message(STATUS "foo1, foo_var_parent is " ${FOO_VAR_PARENT})

function(Foo1)
    # access the local variable outside of the scope of the function 
    message(STATUS "foo1, var1 is " ${VAR1})
    # define a local variable inside the function
    set(FOO_VAR "foo1 var")
    message(STATUS "foo1, foo_var is " ${FOO_VAR})
    # define a local variable with parent scope
    set(FOO_VAR_PARENT "foo1 var" PARENT_SCOPE)
    message(STATUS "foo1, foo_var_parent is " ${FOO_VAR_PARENT})
endfunction()

# call the function
Foo1()

message(STATUS "foo_var is " ${FOO_VAR})
message(STATUS "foo1, foo_var_parent is " ${FOO_VAR_PARENT}) 

# function with arguments
function(Foo2 argList)
    message(STATUS "Foo2 argC:" ${ARGC})
    message(STATUS "Foo2 argV:" ${ARGV})
    message(STATUS "Foo2 argN:" ${ARGN})
    message(STATUS "argv0: " ${ARGV0})
    message(STATUS "argv1: " ${ARGV1})
    message(STATUS "argv2: " ${ARGV2})
#    message(STATUS "argv3: " ${ARGV3})
endfunction(Foo2)

Foo2(A1 A2 A3)