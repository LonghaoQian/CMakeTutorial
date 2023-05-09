message(STATUS "cmd1 VAR1 is " ${VAR1})
#set(VAR1 "cmd1 modified hello")
set(VAR1 "cmd1 modified hello" PARENT_SCOPE)
message(STATUS "cmd1 VAR1 is " ${VAR1})

# set a value in child
set(VAR3 "cmd1  VAR3")

# print the variable defined in root directory
message(STATUS "Var0 " ${VAR0})
# try to change var0
set(VAR0 "cmd1 modified var0" PARENT_SCOPE)