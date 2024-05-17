#include "SquareMatrix.h"
#include <iostream>

//Constructor
SquareMatrix::SquareMatrix() {};
SquareMatrix::SquareMatrix(int size) : m_n(size), m_Matrix(size, std::vector<int>(size)) {}

//Getters
int SquareMatrix::GetN() const { return m_n; }
const std::vector<std::vector<int>>& SquareMatrix::GetMatrix() const { return m_Matrix; }

//Setters
void SquareMatrix::SetN(int size) { m_n = size; }
void SquareMatrix::setMatrix(const std::vector<std::vector<int>>& matrix) { m_Matrix = matrix; }

//Methods
void SquareMatrix::fillMatrix() {
    std::cout << "Enter the elements (integers) of the square matrix " << m_n << "x" << m_n << ":\n";
    for (int i = 0; i < m_n; ++i) {
        for (int j = 0; j < m_n; ++j) {
            std::cout << "Element [" << i << "][" << j << "]: ";
            std::cin >> m_Matrix[i][j];
        }
    }
}

void SquareMatrix::transpositionMatrix() {
    std::vector<std::vector<int>> transposedMatrix(m_n, std::vector<int>(m_n));
    for (int i = 0; i < m_n; ++i) {
        for (int j = 0; j < m_n; ++j) {
            transposedMatrix[i][j] = m_Matrix[j][i];
        }
    }
    m_Matrix = transposedMatrix;
}

void SquareMatrix::makeUpperTriangular() {
    for (int i = 0; i < m_n; ++i) {
        for (int k = i + 1; k < m_n; ++k) {
            int multiplier = m_Matrix[k][i] / m_Matrix[i][i];
            for (int j = i; j < m_n; ++j) {
                m_Matrix[k][j] -= multiplier * m_Matrix[i][j];
            }
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
    for (int i = 0; i < m_n; ++i) {
        for (int j = 0; j < m_n; ++j) {
            m_Matrix[i][j] *= number;
        }
    }
    return *this;
}

SquareMatrix& SquareMatrix::operator+=(const SquareMatrix& matrixSecond) {
    const auto& secondMatrix = matrixSecond.GetMatrix();
    for (int i = 0; i < m_n; ++i) {
        for (int j = 0; j < m_n; ++j) {
            m_Matrix[i][j] += secondMatrix[i][j];
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
