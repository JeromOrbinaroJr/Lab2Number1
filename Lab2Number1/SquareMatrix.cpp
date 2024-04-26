#include "SquareMatrix.h"
#include <iostream>

//Getters
int SquareMatrix::GetN() const { return n; }
const std::vector<std::vector<int>>& SquareMatrix::GetMatrix() const { return Matrix; }

//Setters
void SquareMatrix::SetN(int size) { n = size; }
void SquareMatrix::setMatrix(const std::vector<std::vector<int>>& matrix) { Matrix = matrix; }

//Methods
void SquareMatrix::fillMatrix() {
    std::cout << "Enter the elements (integers) of the square matrix " << n << "x" << n << ":\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "Element [" << i << "][" << j << "]: ";
            std::cin >> Matrix[i][j];
        }
    }
}

void SquareMatrix::transpositionMatrix() {
    std::vector<std::vector<int>> transposedMatrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            transposedMatrix[i][j] = Matrix[j][i];
        }
    }
    Matrix = transposedMatrix;
}

void SquareMatrix::makeUpperTriangular() {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            Matrix[j][i] = 0;
        }
    }
}

void SquareMatrix::printMenu() {
    std::cout << "\n1) Transpose the matrix\n";
    std::cout << "2) Bring the matrix to a triangular shape\n";
    std::cout << "3) Multiply the matrix by a numeric constant\n";
    std::cout << "4) Add up the main matrix with an additional one\n";
    std::cout << "5) Exiting the program...\n";
}

//Operator Overloading
SquareMatrix& SquareMatrix::operator*=(int number) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            Matrix[i][j] *= number;
        }
    }
    return *this;
}

SquareMatrix& SquareMatrix::operator+=(const SquareMatrix& matrixSecond) {
    const auto& secondMatrix = matrixSecond.GetMatrix();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            Matrix[i][j] += secondMatrix[i][j];
        }
    }
    return *this;
}


std::ostream& operator<<(std::ostream& os, const SquareMatrix& matrix) {
    std::cout << "\nThe introduced matrix:\n";
    const auto& Matrix = matrix.GetMatrix();
    for (const auto& row : Matrix) {
        std::cout << "\n";
        for (int elem : row) {
            os << elem << "\t";
        }
        os << "\n";
    }
    return os;
}
