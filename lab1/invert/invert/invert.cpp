#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

const int MATRIX_SIZE_3X3 = 3;
const int MATRIX_SIZE_2X2 = 2;

double** InitializeMatrix(int matrixSize)
{
	double** matrix = new double*[matrixSize];
	for (int i = 0; i < matrixSize; i++)
	{
		matrix[i] = new double[matrixSize];
	}
	return matrix;
}

double GetDeterminant(double** matrix)
{
	double firstTriangle = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1];
	double secondTriangle = matrix[0][2] * matrix[1][1] * matrix[2][0] + matrix[0][0] * matrix[1][2] * matrix[2][1] + matrix[0][1] * matrix[1][0] * matrix[2][2];
	return firstTriangle - secondTriangle;
}

double GetMinor(double** matrix, int i1, int j1)
{
	double** smallMatrix = InitializeMatrix(MATRIX_SIZE_2X2);
	std::vector<double> smallMatrixElements;
	int smallMatrixElementsAdded = 0;

	for (int i = 0; i < MATRIX_SIZE_3X3; i++)
	{
		for (int j = 0; j < MATRIX_SIZE_3X3; j++)
		{
			if (i == i1 or j == j1)
			{
				continue;
			}
			smallMatrixElements.emplace_back(matrix[i][j]);
		}
	}

	for (int i = 0; i < MATRIX_SIZE_2X2; i++)
	{
		for (int j = 0; j < MATRIX_SIZE_2X2; j++)
		{
			smallMatrix[i][j] = smallMatrixElements[smallMatrixElementsAdded];
			smallMatrixElementsAdded++;
		}
	}

	return pow(-1, (i1 + j1 + 2)) * (smallMatrix[0][0] * smallMatrix[1][1] - smallMatrix[0][1] * smallMatrix[1][0]);
}

double** GetTransposedMatrix(double** matrix)
{
	double** transposedMatrix = InitializeMatrix(MATRIX_SIZE_3X3);
	for (int i = 0; i < MATRIX_SIZE_3X3; i++)
	{
		for (int j = 0; j < MATRIX_SIZE_3X3; j++)
		{
			transposedMatrix[j][i] = GetMinor(matrix, i, j);
		}
	}
	return transposedMatrix;
}

double** GetInvertMatrix(double** transposedMatrix, double determinant)
{
	double** invertMatrix = InitializeMatrix(MATRIX_SIZE_3X3);
	for (int i = 0; i < MATRIX_SIZE_3X3; i++)
	{
		for (int j = 0; j < MATRIX_SIZE_3X3; j++)
		{
			invertMatrix[i][j] = 1 / determinant * transposedMatrix[i][j];
		}
	}
	return invertMatrix;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid options count\nExample: invert.exe <matrix file>\n";
		return 1;
	}

	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
	{
		std::cout << "Error with file openning\n";
		return 1;
	}

	double** matrix = InitializeMatrix(MATRIX_SIZE_3X3);
	for (int i = 0; i < MATRIX_SIZE_3X3; i++)
	{
		for (int j = 0; j < MATRIX_SIZE_3X3; j++)
		{
			inputFile >> matrix[i][j];
		}
	}

	double determinant = GetDeterminant(matrix);
	if (determinant == 0)
	{
		std::cout << "Invert matrix isn't exist\n";
		return 1;
	}

	double** transposedMatrix = GetTransposedMatrix(matrix);

	double** invertMatrix = GetInvertMatrix(transposedMatrix, determinant);

	for (int i = 0; i < MATRIX_SIZE_3X3; i++)
	{
		for (int j = 0; j < MATRIX_SIZE_3X3; j++)
		{
			std::cout << round(invertMatrix[i][j] * 1000) / 1000 << ' ';
		}
		std::cout << '\n';
	}
}