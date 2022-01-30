cmake_minimum_required(VERSION 3.21)
project(${LIB_NAME}_ctests LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# set_tests_properties(FirstTest PROPERTIES
#     PASS_REGULAR_EXPRESSION "The result is: 3105"
#     FAIL_REGULAR_EXPRESSION "Error!")

add_executable(Screen_test Screen.cpp)
add_executable(Math_test   Math.cpp)

# add_test(Screen Screen_test)
# add_test(NAME Math COMMAND Math_test)

target_link_libraries(Screen_test ${LIB_NAME} gtest_main)
target_link_libraries(Math_test   ${LIB_NAME} gtest_main)

include(GoogleTest)
gtest_discover_tests(Math_test)
gtest_discover_tests(Screen_test)
