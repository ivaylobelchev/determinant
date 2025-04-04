#include "readFromFile.hpp"

bool readFromFile(int& N, std::vector<std::vector<double>>& mat)
{
	// Prompt the user for the filename and read it.
	std::string fileName;
	std::cout << "Please enter the filename to open: ";
	// Allows for spaces in the filename
	if (!std::getline(std::cin, fileName)) {
		std::cerr << "Error reading the filename!\n";
		return false;
	}

	// Open the file.
	std::ifstream textFile{ fileName };
	if (!textFile.is_open()) {
		std::cerr << "Error opening text file: " << fileName << '\n';
		return false;
	}

	// Read the size of the matrix.
	if (!(textFile >> N)) {
		std::cerr << "Error reading matrix size!\n";
		return false;
	}
	if (N < 0) {
		std::cerr << "The matrix size cannot be a negative number!\n";
		return false;
	}

	// Resize the vectors to hold N elements. Read each element and add them to the matrix.
	mat.resize(N);
	for (int i = 0; i < N; ++i) {
		mat[i].resize(N);
		for (int j = 0; j < N; ++j) {
			if (!(textFile >> mat[i][j])) {
				std::cerr << "Error reading matrix element at (" << i << ", " << j << ")\n";
				return false;
			}
		}
	}

	textFile.close();
	return true;
}