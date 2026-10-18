find_package(GTest REQUIRED)

add_executable(matrix_tests test_matrix.cpp ../src/matrix.cpp)

target_include_directories(matrix_tests PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(matrix_tests PRIVATE 
    GTest::gtest 
    GTest::gtest_main 
    pthread
)

include(GoogleTest)
gtest_discover_tests(matrix_tests)