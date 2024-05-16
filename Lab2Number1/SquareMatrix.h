#pragma once
#include <vector>
#include <iostream>

class SquareMatrix {
public:
	// Constructor
	SquareMatrix(int size) : m_n(size), m_Matrix(size, std::vector<int>(size)) { }

	//Destructor
	~SquareMatrix() { }

	// Getters
	int GetN() const;
	const std::vector<std::vector<int>>& GetMatrix() const;

	// Setters
	void SetN(int size);
	void setMatrix(const std::vector<std::vector<int>>& matrix);

	//Methods
	void fillMatrix();
	void transpositionMatrix();
	void makeUpperTriangular();
	void printMenu();

	//Operator Overloading
	friend std::ostream& operator<<(std::ostream& os, const SquareMatrix& matrix);
	SquareMatrix& operator*=(int number);
	SquareMatrix& operator+=(const SquareMatrix& matrixSecond);

private:
	int m_n;
	std::vector<std::vector<int>>m_Matrix;
	std::vector<std::vector<int>>m_MatrixSecond;
};