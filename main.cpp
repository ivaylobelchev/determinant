#include "readFromFile.hpp"
#include "determinantN.hpp"

int main()
{
	// Read number of elements and the matrix from a file
	int N;
	std::vector<std::vector<double>> mat;
	if (readFromFile(N, mat) == false) {
		return 1;
	}

	// Find and output the determinant
	std::cout << "Determinant: " << DeterminantN(N, mat).result() << '\n';
	
	return 0;
}