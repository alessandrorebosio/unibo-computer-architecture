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
        xor eax, eax; // Clear eax (used as row index for mat1)
    row_loop:
        cmp eax, m; // Compare row index (eax) with m
        jge end; // If eax >= m, jump to end

        xor ebx, ebx; // Clear ebx (used as column index for mat2)
    column_loop:
        cmp ebx, k; // Compare column index (ebx) with k
        jge next_row; // If ebx >= k, jump to next_row

        xor ecx, ecx; // Clear ecx (used as column index for mat1)
        xor edx, edx; // Clear edx (accumulator for row-product)

    multiply_loop:
        cmp ecx, n; // Compare column index (ecx) with n
        jge store_result; // If ecx >= n, jump to store_result

        mov esi, eax; // Copy the current row index (eax) to esi
        imul esi, n; // Multiply by number of columns in mat1
        add esi, ecx; // Add the column index (ecx)
        shl esi, 1; // Multiply by 2 (to account for short size)
        movsx esi, word ptr [mat1 + esi]; // Load mat1[esi] into esi (signed value)

        mov edi, ecx; // Copy column index (ecx) to edi
        imul edi, k; // Multiply by number of columns in mat2
        add edi, ebx; // Add the row index (ebx)
        shl edi, 1; // Multiply by 2 (to account for short size)
        movsx edi, word ptr [mat2 + edi]; // Load mat2[edi] into edi (signed value)

        imul esi, edi; // Multiply mat1[esi] with mat2[edi]
        add edx, esi; // Accumulate the result in edx

        inc ecx; // Increment column index for mat1
        jmp multiply_loop; // Jump back to multiply_loop to process next column

    store_result:
        mov esi, eax; // Copy row index (eax) to esi
        imul esi, k; // Multiply by number of columns in mat2
        add esi, ebx; // Add the column index (ebx)
        shl esi, 2; // Multiply by 4 (to account for int size)
        mov [mat3 + esi], edx; // Store the accumulated result in mat3

        inc ebx; // Increment column index for mat2
        jmp column_loop; // Jump back to column_loop to process next column

    next_row:
        inc eax; // Increment row index for mat1
        jmp row_loop; // Jump back to row_loop to process next row

    end:
    }

    // Output the result matrix
    unsigned int i, j;
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
