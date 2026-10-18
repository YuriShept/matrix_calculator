#include "matrix.h"
#include <iostream>

int main() {
    try {
        // Создание матриц (пример из методички)
        double dataA[] = {1.0, 2.0, 3.0, 4.0};
        double dataB[] = {5.0, 6.0, 7.0, 8.0};
        
        Matrix A = matrix_from_array(dataA, 2, 2);
        Matrix B = matrix_from_array(dataB, 2, 2);

        // Операции
        Matrix sum = matrix_add(A, B);
        Matrix product = matrix_multiply(A, B);

        // Вывод результата
        std::cout << "Matrix A:\n";
        print_matrix(A);
        
        std::cout << "\nSum A+B:\n";
        print_matrix(sum);
        
        std::cout << "\nProduct A*B:\n";
        print_matrix(product);

        // Индивидуальное задание (Вариант 29)
        double threshold = 2.5;
        int count = matrix_count_nonzero(sum, threshold);
        std::cout << "\nCount of elements > " << threshold << " in Sum: " << count << "\n";

        // Освобождение памяти
        free_matrix(A);
        free_matrix(B);
        free_matrix(sum);
        free_matrix(product);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}