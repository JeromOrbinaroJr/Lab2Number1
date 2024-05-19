#include <iostream>
#include <vector>
#include <stdexcept> // Для std::invalid_argument
#include "SquareMatrix.h"

int main() {
    // Ввод размера матрицы
    int size;
    std::cout << "Enter the number of rows and columns of your matrix: ";
    std::cin >> size;

    try {
        SquareMatrix matrix(size);
        matrix.fillMatrix();
        std::cout << matrix;

        char choiceMenu;
        while (true) {
            matrix.printMenu();
            std::cin >> choiceMenu;

            switch (choiceMenu) {
            case '1':
                // Транспонирование матрицы
                matrix.transpositionMatrix();
                std::cout << matrix;
                break;
            case '2':
                // Приведение матрицы к верхнетреугольной форме
                matrix.makeUpperTriangular();
                std::cout << matrix;
                break;
            case '3':
                // Умножение матрицы на число
                int number;
                std::cout << "Enter a number to multiply matrix by: ";
                std::cin >> number;
                matrix *= number;
                std::cout << matrix;
                break;
            case '4':
            {
                // Сложение с другой матрицей
                SquareMatrix matrixSecond(size);
                matrixSecond.fillMatrix();
                std::cout << "Second matrix:\n" << matrixSecond;
                matrix += matrixSecond;
                std::cout << "Result after addition:\n" << matrix;
            }
            break;
            case '5':
                std::cout << "Exiting the program...";
                return 0;
            default:
                std::cout << "Invalid choice.\n";
                break;
            }
        }
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}

    //Демо матрица

    //char choiceMenu;
    //int number;
    //SquareMatrix matrix;
    //matrix.SetN(3);
    //matrix.setMatrix({ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } });
    //std::cout << matrix;

    //while (true) {
    //    matrix.printMenu();
    //    std::cin >> choiceMenu;
    //    switch (choiceMenu) {
    //    case '1':
    //        // Transposition
    //        matrix.transpositionMatrix();
    //        std::cout << matrix;
    //        break;

    //    case '2':
    //        // Upper triangular matrix
    //        matrix.makeUpperTriangular();
    //        std::cout << matrix;
    //        break;

    //    case '3':
    //        // Multiplication
    //        std::cout << "Enter a number to multiply matrix by: ";
    //        std::cin >> number;
    //        matrix *= number;
    //        std::cout << matrix;
    //        break;

    //    case '4':
    //    {
    //        SquareMatrix matrixSecond(3);
    //        matrixSecond.fillMatrix();
    //        std::cout << matrix;
    //        matrix += matrixSecond;
    //        std::cout << matrix;
    //    }
    //    break;

    //    case '5':
    //        std::cout << "Exiting the program...";
    //        return 0;

    //    default:
    //        std::cout << "Invalid choice.";
    //        break;
    //    }
    //}
//
//    return 0;
//}