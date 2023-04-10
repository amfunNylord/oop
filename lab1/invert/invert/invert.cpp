#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include <optional>

const int MATRIX_SIZE_3X3 = 3;
const int MATRIX_SIZE_2X2 = 2;

using Mat3x3 = std::array<std::array<double, 3>, 3>;
using Mat2x2 = std::array<std::array<double, 2>, 2>;

double GetDeterminant(Mat3x3 matrix)
{
	double firstTriangle = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1];
	double secondTriangle = matrix[0][2] * matrix[1][1] * matrix[2][0] + matrix[0][0] * matrix[1][2] * matrix[2][1] + matrix[0][1] * matrix[1][0] * matrix[2][2];
	return firstTriangle - secondTriangle;
}

double GetMinor(Mat3x3 matrix, int i1, int j1)
{
	Mat2x2 smallMatrix;
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
	// разбить
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

Mat3x3 GetTransposedMatrix(Mat3x3 matrix)
{
	Mat3x3 transposedMatrix;
	for (int i = 0; i < MATRIX_SIZE_3X3; i++)
	{
		for (int j = 0; j < MATRIX_SIZE_3X3; j++)
		{
			transposedMatrix[j][i] = GetMinor(matrix, i, j);
		}
	}
	return transposedMatrix;
}

Mat3x3 InvertMatrix(double determinant, Mat3x3 transposedMatrix)
{
	Mat3x3 invertMatrix;
	for (int i = 0; i < MATRIX_SIZE_3X3; i++)
	{
		for (int j = 0; j < MATRIX_SIZE_3X3; j++)
		{
			invertMatrix[i][j] = 1 / determinant * transposedMatrix[i][j];
		}
	}
}

std::optional<Mat3x3> GetInvertMatrix(Mat3x3 matrix)
{
	double determinant = GetDeterminant(matrix);
	if (determinant == 0)
	{
		std::cout << "Invert matrix isn't exist\n";
		return std::nullopt;
	}

	Mat3x3 transposedMatrix = GetTransposedMatrix(matrix);

	Mat3x3 invertMatrix = InvertMatrix(determinant, transposedMatrix);

	return invertMatrix;
}

void PrintMatrix(std::optional<Mat3x3> invertMatrix)
{
	for (int i = 0; i < MATRIX_SIZE_3X3; i++)
	{
		for (int j = 0; j < MATRIX_SIZE_3X3; j++)
		{
			std::cout << round(invertMatrix[i][j] * 1000) / 1000 << ' ';
		}
		std::cout << '\n';
	}
}

void ReadMatrix(std::ifstream& inputFile, Mat3x3& matrix)
{
	for (int i = 0; i < MATRIX_SIZE_3X3; i++)
	{
		for (int j = 0; j < MATRIX_SIZE_3X3; j++)
		{
			inputFile >> matrix[i][j];
		}
	}
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

	Mat3x3 matrix;
	ReadMatrix(inputFile, matrix);

	std::optional<Mat3x3> invertMatrix = GetInvertMatrix(matrix);

	if (invertMatrix == std::nullopt)
	{
		return 1;
	}

	PrintMatrix(invertMatrix);
}