cmake_minimum_required(VERSION 3.24)
project(Oop_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-static")

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(Oop_1 main.cpp main.cpp 1-4/replace.cpp 3-2/invert.cpp 2-6/radix.cpp 2-6/radix.h)
add_executable(crypt 4-3/crypt.cpp 4-3/cryptFunctions.cpp)
add_executable(decrypt 4-3/crypt.cpp 4-3/cryptFunctions.cpp)

add_executable(crypt_tests 4-3/tests/cryptTest.cpp 4-3/cryptFunctions.cpp)

target_link_libraries(crypt_tests gtest_main)
