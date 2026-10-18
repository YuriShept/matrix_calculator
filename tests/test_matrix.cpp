#include <gtest/gtest.h>
#include "matrix.h"
#include <stdexcept>

// ================= 1. НОРМАЛЬНЫЕ СЛУЧАИ =================

TEST(MatrixTest, CreateMatrix_NormalCase) {
    Matrix A = create_matrix(3, 4);
    EXPECT_EQ(A.rows, 3);
    EXPECT_EQ(A.cols, 4);
    EXPECT_NE(A.data, nullptr);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            EXPECT_DOUBLE_EQ(A.data[i][j], 0.0);
        }
    }
    free_matrix(A);
}

TEST(MatrixTest, Addition_NormalCase) {
    double dataA[] = {1, 2, 3, 4};
    double dataB[] = {5, 6, 7, 8};
    Matrix A = matrix_from_array(dataA, 2, 2);
    Matrix B = matrix_from_array(dataB, 2, 2);

    Matrix C = matrix_add(A, B);
    EXPECT_DOUBLE_EQ(C.data[0][0], 6.0);
    EXPECT_DOUBLE_EQ(C.data[0][1], 8.0);
    EXPECT_DOUBLE_EQ(C.data[1][0], 10.0);
    EXPECT_DOUBLE_EQ(C.data[1][1], 12.0);

    free_matrix(A); free_matrix(B); free_matrix(C);
}

TEST(MatrixTest, Multiplication_NormalCase) {
    double dataA[] = {1, 2, 3, 4};
    double dataB[] = {5, 6, 7, 8};
    Matrix A = matrix_from_array(dataA, 2, 2);
    Matrix B = matrix_from_array(dataB, 2, 2);

    Matrix C = matrix_multiply(A, B);
    EXPECT_DOUBLE_EQ(C.data[0][0], 19.0);
    EXPECT_DOUBLE_EQ(C.data[0][1], 22.0);
    EXPECT_DOUBLE_EQ(C.data[1][0], 43.0);
    EXPECT_DOUBLE_EQ(C.data[1][1], 50.0);

    free_matrix(A); free_matrix(B); free_matrix(C);
}

// Тест для вашего 29-го варианта
TEST(MatrixTest, CountNonzero_NormalCase) {
    double data[] = {1.5, -2.0, 3.5, -4.0, 0.5, 0.0};
    Matrix M = matrix_from_array(data, 2, 3);
    
    // Порог 1.0: модули 1.5, 2.0, 3.5, 4.0 больше 1.0 (4 штуки)
    EXPECT_EQ(matrix_count_nonzero(M, 1.0), 4);
    free_matrix(M);
}

// ================= 2. ГРАНИЧНЫЕ СЛУЧАИ =================

TEST(MatrixTest, CreateMatrix_MinimumSize) {
    Matrix A = create_matrix(1, 1);
    EXPECT_EQ(A.rows, 1);
    EXPECT_EQ(A.cols, 1);
    EXPECT_DOUBLE_EQ(A.data[0][0], 0.0);
    free_matrix(A);
}

// ================= 3. НЕКОРРЕКТНЫЕ СЛУЧАИ =================

TEST(MatrixTest, CreateMatrix_ZeroRows) {
    EXPECT_THROW(create_matrix(0, 3), std::invalid_argument);
}

TEST(MatrixTest, CreateMatrix_NegativeCols) {
    EXPECT_THROW(create_matrix(3, -1), std::invalid_argument);
}

TEST(MatrixTest, Addition_SizeMismatch) {
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(3, 3);
    EXPECT_THROW(matrix_add(A, B), std::invalid_argument);
    free_matrix(A); free_matrix(B);
}

TEST(MatrixTest, Multiplication_SizeMismatch) {
    Matrix A = create_matrix(2, 3);
    Matrix B = create_matrix(2, 2);
    EXPECT_THROW(matrix_multiply(A, B), std::invalid_argument);
    free_matrix(A); free_matrix(B);
}