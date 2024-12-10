# Project 2: Matrix Multiplication (WORD to DWORD)

#### Description:
This project involves the multiplication of two matrices where elements are represented by **16-bit signed integers (WORD)**. The result matrix is a **32-bit signed integer (DWORD)**. The matrices are represented as one-dimensional arrays in memory, and the program calculates their product using assembly code.

#### Key Features:
- **Input:** Two matrices (`mat1` and `mat2`), each containing 16-bit signed integers.
- **Output:** A result matrix `mat3` of 32-bit signed integers.
- **Assembly Code:** Matrix multiplication is implemented using assembly, with multiplication of individual matrix elements followed by accumulation.
- **Challenge:** Implementing efficient matrix multiplication using low-level operations in assembly.

#### Code:
```c
#include <stdio.h>

void main() {
    unsigned int m = 3, n = 2, k = 4;
    short int mat1[] = {-1, -2, 4, 5, 4, -2}; 
    short int mat2[] = {2, 0, 0, 0, 0, 2, 0, 0};
    int mat3[1024];

    __asm {
        // Assembly code for matrix multiplication
    }

    unsigned int i, j, h;
    printf("Matrice prodotto:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < k; j++) {
            printf("%6d ", mat3[i * k + j]);
        }
        printf("\n");
    }
}
```