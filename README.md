# Determinant Calculator

## Overview

This program computes the determinant of an **NxN matrix** from a text file.  
It reads the matrix from the file, stores it in a **vector**, and calculates the determinant using the `DeterminantN` class.

## Notes

The method implemented here is a Laplace expansion of the determinant until it gets broken down to a 2x2 matrix, which gets calculated with the `|A| = ad - bc` formula.
I chose NOT to use the more efficient Gaussian elimination algorithm, because it can cause round-off errors when implemented using floating-point numbers. One of the objectives of this solution was to be able to use floating-point numbers. The Laplace expansion algorithm has a O(n!) complexity, while the Gaussian elimination algorithm has a O(n^3) complexity.

## Requirements

- **C++11 or later** (the program was written using C++14).
- A compiler that supports C++11 (e.g., **GCC 4.9+, Clang 3.3+, MSVC 2015+**)

### Files

Ensure the following files are in the same directory:

- `main.cpp`
- `readFromFile.hpp`
- `readFromFile.cpp`
- `determinantN.hpp`
- `determinantN.cpp`

## Usage

1. **Compile the program**:
   ```sh
   g++ -std=c++14 main.cpp readFromFile.cpp determinantN.cpp -o determinant_calculator
   ```
2. **Run the program**:
   ```sh
   ./determinant_calculator
   ```
3. **Enter the filename** containing the matrix when prompted.

The matrix in the file should be formatted in the following format:

```
4
12.2  0.5   11.0  3.1
4.0   63.5  12.8  0.1
0.0   1.2   -0.7  16.0
6.31  9.85  1.15  0.86
```

The first line should contain N, the size of the NxN matrix. The rest of the file should contain N^2 floating-point numbers, separates only by spaces, tabs or new lines. Ensure that your input files are formatted correctly for the program to process them successfully.

### Test Data

Test matrices are available in the **"test_data"** directory.  
For example, to test a **4×4 matrix**, enter:

```
test_data/det4.txt
```

### Output

- The program prints the **determinant** of the given matrix.
- It returns **0** on success or a **nonzero value** if an error occurs.

### Error Handling

- If the file cannot be opened, an **error message** is displayed.
