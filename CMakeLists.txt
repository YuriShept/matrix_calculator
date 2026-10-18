cmake_minimum_required(VERSION 3.20)
project(Matrix_Calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Основная программа
add_executable(matrix_calculator src/main.cpp src/matrix.cpp)

# Включаем тестирование и подключаем папку tests
enable_testing()
add_subdirectory(tests)