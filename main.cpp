#include <iostream>
#include <fstream>
#include <string>
#include "determinantN.hpp"

int main()
{
	std::string fileName;
	std::cout << "Please enter the filename to open: ";
	std::cin >> fileName;

	std::ifstream textFile{ fileName };

	if (!textFile.is_open()) {
		std::cerr << "Error opening text file: " << fileName << '\n';
		return 1;
	}

	int N;
	if (!(textFile >> N)) {
		std::cerr << "Error reading matrix size!\n";
		return 2;
	}
	if (N < 0) {
		std::cerr << "The matrix size cannot be a negative number!\n";
		return 3;
	}

	std::vector<std::vector<double>> mat;
	mat.resize(N);
	for (int i = 0; i < N; ++i) {
		mat[i].resize(N);
		for (int j = 0; j < N; ++j) {
			if (!(textFile >> mat[i][j])) {
				std::cerr << "Error reading matrix element at (" << i << ", " << j << ")\n";
				return 4;
			}
		}
	}

	textFile.close();

	std::cout << "Determinant: " << DeterminantN(N, mat).result();
	
	return 0;
}