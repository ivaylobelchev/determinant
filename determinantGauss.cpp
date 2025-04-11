#include "determinantGauss.hpp"

bool swapRow(std::vector<std::vector<long double>>& matrix, int row1, int row2)
{
	if (row1 < 0 || row2 < 0) return false;
	std::vector<long double> temp = matrix[row1];
	matrix[row1] = matrix[row2];
	matrix[row2] = temp;
	return true;
}

long double DeterminantGauss::result() const
{
	// Base cases: when the matrix is 0x0, 1x1, or 2x2:
	if (N == 0) {
		return 1;
	}
	else if (N == 1) {
		return matr[0][0];
	}
	else if (N == 2) {
		return (long double)(matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0]);
	}
	// When the matrix is 3x3 or larger:
	else {
		std::vector<std::vector<long double>> mat = matr;
		// Pivot rows
		for (int i = 0; i < this->N; ++i) {
			// (i, i) is my pivot

			// Check if pivot is 0
			if (mat[i][i] == 0) {
				// We swap row i with a row that doesn't have a 0 in this column
				int row1 = i, row2 = -1;
				for (int row = i + 1; row < this->N; ++row) {
					if (mat[row][i] != 0) {
						row2 = row;
						break;
					}
				}
				if (!swapRow(mat, row1, row2)) return 0;
			}

			for (int row = i + 1; row < this->N; ++row) {
				// value to eliminate the values
				long double elimination = -(mat[row][i] / mat[i][i]);
				for (int col = i; col < this->N; ++col) {
					mat[row][col] += elimination * mat[i][col];
				}
			}
		}
		
		// Multiply all the diagonals
		long double det = 1;
		for (int i = 0; i < this->N; ++i) {
			det *= mat[i][i];
		}
		return det;
	}
}