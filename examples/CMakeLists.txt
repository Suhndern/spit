add_executable (Lorem lorem.cpp)
add_executable (Switch switch.cpp)
add_executable (StringLen string-len.cpp)

set_property (TARGET Lorem PROPERTY CXX_STANDARD 17)
set_property (TARGET Switch PROPERTY CXX_STANDARD 17)
set_property (TARGET StringLen PROPERTY CXX_STANDARD 17)

add_custom_command(
    TARGET Lorem PRE_LINK
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/examples/lorem.txt
            ${CMAKE_CURRENT_BINARY_DIR}/lorem.txt)
