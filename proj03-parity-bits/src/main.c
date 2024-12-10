/********************************************************************************
 *                                                                              *
 *                   System Architecture Programming Assignment                 *
 *                                                                              *
 ********************************************************************************

 Project 3
 Description: Given a sequence of bits, where each n bits (of data) is followed
              by a parity bit (1 if the number of 1-bits in the preceding n bits
              is odd), verify if there are errors in the sequence.

 ********************************************************************************/

#include <stdio.h>

void main()
{
    // Input
    unsigned char vet[] = {0x7B, 0xB0, 0xBB, 0xD3, 0xC0, 0xD2, 0xD3, 0x18, 0xBB, 0x4F, 0x29, 0x62};
    unsigned int len = 95; // Length in bits
    unsigned char n = 4;   // Number of data bits

    // Output
    unsigned char error_flag = 0; // 1 = errors found; 0 = no errors

    __asm {
        // Assembly code for error detection
    }

    // Output result
    printf("The bit sequence %scontains errors\n", (error_flag ? "" : "does not "));
}
