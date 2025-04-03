# Determinant Calculator

## Overview

This program computes the determinant of an **NxN matrix** from a text file.  
It reads the matrix from the file, stores it in a **vector**, and calculates the determinant using the `DeterminantN` class.

## Requirements

- **C++11 or later** (the program was written using C++14).
- A compiler that supports C++11 (e.g., **GCC 4.8+, Clang 3.3+, MSVC 2013+**)
- The files **"main.cpp"** and **"determinantN.hpp"** must be in the same directory.

## Usage

1. **Compile the program**:
   ```sh
   g++ -std=c++14 -o determinant_calculator main.cpp
   ```
2. **Run the program**:
   ```sh
   ./determinant_calculator
   ```
3. **Enter the filename** containing the matrix when prompted.

## Example

Test matrices are available in the **"test_data"** directory.  
For example, to test a **4×4 matrix**, enter:

```
test_data/det4.txt
```

## Output

- The program prints the **determinant** of the given matrix.
- It returns **0** on success or a **nonzero value** if an error occurs.

## Error Handling

- If the file cannot be opened, an **error message** is displayed.
