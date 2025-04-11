#pragma once
#include <vector>

class DeterminantGauss
{
private:
	int N;
	std::vector<std::vector<long double>> matr;
public:
	DeterminantGauss(int N, const std::vector<std::vector<long double>>& matrix)
		: N(N), matr(matrix)
	{};
	long double result() const;
};