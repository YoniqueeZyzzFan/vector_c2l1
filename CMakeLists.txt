# CMakeList.txt : CMake project for vector_CMAKE, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("vector_CMAKE")

# Включение высокого уровня предупреждений
if(MSVC) # Компилятор MSVC /W3
    if(CMAKE_C_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
    else()
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4")
    endif()
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    add_compile_options(/experimental:external /external:anglebrackets /external:W0)
elseif(CMAKE_COMPILER_IS_GNUCC) # Компилятор GCC
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wconversion -Wextra -Wpedantic")
endif()

# Add source to this project's executable.
add_executable (vectorcpp "main.cpp")