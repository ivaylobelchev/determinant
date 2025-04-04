#pragma once
#include <vector>

class DeterminantN
{
private:
	int N;
	std::vector<std::vector<double>> matr;
public:
	DeterminantN(int N, const std::vector<std::vector<double>>& matrix)
		: N(N), matr(matrix)
	{};
	double result() const;
};