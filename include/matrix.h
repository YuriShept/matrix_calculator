/**
 * @file matrix.h
 * @brief Библиотека для работы с матрицами.
 * @author Студент (Шептунов Юрий)
 * @version 0.1
 */

#pragma once

/**
 * @brief Структура матрицы.
 * 
 * Хранит двумерный динамический массив и его размеры.
 * @warning Память освобождается через free_matrix().
 */
typedef struct {
    double** data; //< Указатель на двумерный массив.
    int rows;      //< Количество строк.
    int cols;      //< Количество столбцов.
} Matrix;

/**
 * @brief Создание матрицы заданного размера.
 * 
 * @param rows Количество строк (> 0).
 * @param cols Количество столбцов (> 0).
 * @return Matrix Инициализированная нулями матрица.
 * @exception std::invalid_argument Если rows <= 0 или cols <= 0.
 * @exception std::bad_alloc Если не удалось выделить память.
 * @note Время выполнения: O(rows * cols).
 * @see free_matrix()
 * @code
 * Matrix A = create_matrix(3, 3);
 * @endcode
 */
Matrix create_matrix(int rows, int cols);

/**
 * @brief Освобождение памяти, занятой матрицей.
 * @param m Матрица, память которой нужно освободить.
 */
void free_matrix(Matrix m);

/**
 * @brief Сложение двух матриц.
 * @param a Первая матрица.
 * @param b Вторая матрица.
 * @return Matrix Результат сложения.
 * @exception std::invalid_argument Если размеры матриц не совпадают.
 */
Matrix matrix_add(Matrix a, Matrix b);

/**
 * @brief Умножение двух матриц.
 * @param a Матрица M×N.
 * @param b Матрица N×K.
 * @return Matrix Результат M×K.
 * @exception std::invalid_argument Если cols(a) != rows(b).
 * @note Время выполнения: O(M*N*K).
 * @warning Результат нужно освобождать через free_matrix().
 */
Matrix matrix_multiply(Matrix a, Matrix b);

/**
 * @brief Вывод матрицы в консоль.
 * @param m Матрица для вывода.
 */
void print_matrix(Matrix m);

/**
 * @brief Создание матрицы из одномерного массива.
 * @param data Указатель на массив.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @return Matrix Новая матрица.
 */
Matrix matrix_from_array(double* data, int rows, int cols);

/**
 * @brief Подсчет ненулевых элементов (Вариант 29).
 * @param m Матрица.
 * @param threshold Порог.
 * @return int Количество элементов, модуль которых больше порога.
 */
int matrix_count_nonzero(Matrix m, double threshold);