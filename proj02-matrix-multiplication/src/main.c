#include <stdio.h>

/********************************************************************************
 *                                                                              *
 *                   Computer Systems Architecture                              *
 *                                                                              *
 ********************************************************************************

 Project 2
 Description: Compute the DWORD product matrix of two WORD matrices.
              The matrices are stored by rows within one-dimensional arrays.
              The matrix elements are signed (in two's complement).
 ********************************************************************************/

void main()
{
    unsigned int m = 3;                          // Number of rows in the first matrix
    unsigned int n = 2;                          // Number of columns in the first matrix
    unsigned int k = 4;                          // Number of columns in the second matrix
    short int mat1[] = {-1, -2, 4, 5, 4, -2};    // First matrix (m x n)
    short int mat2[] = {2, 0, 0, 0, 0, 2, 0, 0}; // Second matrix (n x k)
    int mat3[1024];                              // Result matrix (m x k)

    __asm {
        // Assembly code for matrix multiplication
    }

    // Output the result matrix
    unsigned int i, j, h;
    printf("Matrix product:\n");
    for (i = 0; i < m; i++) // Iterate through rows of the result matrix
    {
        for (j = 0; j < k; j++) // Iterate through columns of the result matrix
        {
            printf("%6d ", mat3[i * k + j]); // Print each element with a width of 6 characters
        }
        printf("\n"); // New line after each row
    }
}
