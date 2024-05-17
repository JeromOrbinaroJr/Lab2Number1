#include <iostream>
#include "SquareMatrix.h"

int main() {
    //¬вод матрицы вручную 

    //int n, number;
    //char choiceMenu;
    //std::cout << "Enter the number of rows and columns of your matrix: ";
    //std::cin >> n;
    //try {
    //    if (n <= 0) { throw n; }
    //    SquareMatrix matrix(n);
    //    matrix.fillMatrix();
    //    std::cout << matrix;

    //    while (true) {
    //        matrix.printMenu();
    //        std::cin >> choiceMenu;
    //        switch (choiceMenu) {
    //        case '1':
    //            // Transposition
    //            matrix.transpositionMatrix();
    //            std::cout << matrix;
    //            break;
    //        case '2':
    //            // Upper triangular matrix
    //            matrix.makeUpperTriangular();
    //            std::cout << matrix;
    //            break;
    //        case '3':
    //            // Multiplication
    //            std::cout << "Enter a number to multiply matrix by: ";
    //            std::cin >> number;
    //            matrix *= number;
    //            std::cout << matrix;
    //            break;
    //        case '4':
    //        {
    //            SquareMatrix matrixSecond(n);
    //            matrixSecond.fillMatrix();
    //            std::cout << matrix;
    //            matrix += matrixSecond;
    //            std::cout << matrix;
    //        }
    //        break;
    //        case '5':
    //            std::cout << "Exiting the program...";
    //            return 0;
    //        default:
    //            std::cout << "Invalid choice.";
    //            break;
    //        }
    //    }
    //}
    //catch (int n) {
    //    std::cout << "You have entered an incorrect number of rows and columns.";
    //}

    //ƒемо матрица

    char choiceMenu;
    int number;
    SquareMatrix matrix;
    matrix.SetN(3);
    matrix.setMatrix({ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } });
    std::cout << matrix;

    while (true) {
        matrix.printMenu();
        std::cin >> choiceMenu;
        switch (choiceMenu) {
        case '1':
            // Transposition
            matrix.transpositionMatrix();
            std::cout << matrix;
            break;
        case '2':
            // Upper triangular matrix
            matrix.makeUpperTriangular();
            std::cout << matrix;
            break;
        case '3':
            // Multiplication
            std::cout << "Enter a number to multiply matrix by: ";
            std::cin >> number;
            matrix *= number;
            std::cout << matrix;
            break;
        case '4':
        {
            SquareMatrix matrixSecond(3);
            matrixSecond.fillMatrix();
            std::cout << matrix;
            matrix += matrixSecond;
            std::cout << matrix;
        }
        break;
        case '5':
            std::cout << "Exiting the program...";
            return 0;
        default:
            std::cout << "Invalid choice.";
            break;
        }
    }

    return 0;
}