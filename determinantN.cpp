#include "determinantN.hpp"

double DeterminantN::result() const
{
	// Base cases: when the matrix is 0x0, 1x1, or 2x2:
	if (N == 0) {
		return 1;
	}
	else if (N == 1) {
		return matr[0][0];
	}
	else if (N == 2) {
		return (double)(matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0]);
	}
	// When the matrix is 3x3 or larger:
	else {
		double result = 0.0;
		// Expand along the first row
		for (int i = 0; i < N; ++i) {
			// Create a sub-matrix to use in a recursive function
			std::vector<std::vector<double>> subMatrix;
			// Resize the sub-matrix
			subMatrix.resize(N - 1);
			for (int j = 0; j < N - 1; ++j) {
				subMatrix[j].resize(N - 1);
			}
			// Add data to the sub-matrix by excluding the first row and the i-th column
			for (int row = 1; row < N; ++row) {
				for (int column = 0; column < N; ++column) {
					if (column < i) {
						subMatrix[row - 1][column] = matr[row][column];
					}
					else if (column > i) {
						subMatrix[row - 1][column - 1] = matr[row][column];
					}
				}
			}
			// Recursively calculate the determinant of the sub-matrix
			double subDet = (double)DeterminantN(N - 1, subMatrix).result();
			result += (i % 2 == 0 ? 1 : -1) * matr[0][i] * subDet;
		}
		return result;
	}
}