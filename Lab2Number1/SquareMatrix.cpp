#include "SquareMatrix.h"

SquareMatrix::SquareMatrix(int size) : m_size(size) {
    if (size <= 0) {
        throw std::invalid_argument("Matrix size must be greater than zero.");
    }
    m_Matrix = u_Matrix(size, std::vector<int>(size));
}

//Getters
int SquareMatrix::GetN() const { return m_size; }
const u_Matrix& SquareMatrix::GetMatrix() const { return m_Matrix; }

//Setters
void SquareMatrix::SetN(int size) { m_size = size; }
void SquareMatrix::setMatrix(const u_Matrix& matrix) { m_Matrix = matrix; }

//Methods
void SquareMatrix::fillMatrix() {
    std::cout << "Enter the elements (integers) of the square matrix " << m_size << "x" << m_size << ":\n";
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            bool validInput = false;
            do {
                std::cout << "Element [" << i << "][" << j << "]: ";
                if (std::cin >> m_Matrix[i][j]) {
                    validInput = true;
                }
                else {
                    std::cout << "Invalid input. Please enter an integer.\n" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            } while (!validInput);
        }
    }
}

void SquareMatrix::transpositionMatrix() {
    u_Matrix transposedMatrix(m_size, std::vector<int>(m_size));
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            transposedMatrix[i][j] = m_Matrix[j][i];
        }
    }
    m_Matrix = transposedMatrix;
}

void SquareMatrix::makeUpperTriangular() {
    for (int i = 0; i < m_size; ++i) {
        for (int k = i + 1; k < m_size; ++k) {
            int multiplier = m_Matrix[k][i] / m_Matrix[i][i];
            for (int j = i; j < m_size; ++j) {
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
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            m_Matrix[i][j] *= number;
        }
    }
    return *this;
}

SquareMatrix& SquareMatrix::operator+=(const SquareMatrix& matrixSecond) {
    const u_Matrix& secondMatrix = matrixSecond.GetMatrix();
    if (m_size != matrixSecond.GetN()) {
        throw std::invalid_argument("Matrix sizes don't match for addition.");
    }
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            m_Matrix[i][j] += secondMatrix[i][j];
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const SquareMatrix& matrix) {
    std::cout << "\nThe introduced matrix:\n";
    const u_Matrix& Matrix = matrix.GetMatrix();
    for (const auto& row : Matrix) {
        std::cout << "\n";
        for (int elem : row) {
            os << elem << "\t";
        }
        os << "\n";
    }
    return os;
}
