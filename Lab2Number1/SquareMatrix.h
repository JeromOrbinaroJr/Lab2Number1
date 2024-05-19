#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>
using u_Matrix = std::vector<std::vector<int>>;

class SquareMatrix {
public:
	// Constructors
	SquareMatrix() = default;
	explicit SquareMatrix(int size);

	//Destructor
	~SquareMatrix() { }

	// Getters
	int GetN() const;
	const u_Matrix& GetMatrix() const;

	// Setters
	void SetN(int size);
	void setMatrix(const u_Matrix& matrix);

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
	int m_size{ 0 };
	u_Matrix m_Matrix;
	u_Matrix m_MatrixSecond;
};