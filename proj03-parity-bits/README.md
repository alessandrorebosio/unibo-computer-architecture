# Project 3: Error Detection in Parity Bits

#### Description:
This project is focused on detecting errors in a sequence of data bits, where every `n` bits of data is followed by a parity bit. The parity bit is set to 1 if the number of `1` bits among the previous `n` data bits is odd, and to 0 if it's even. The goal is to verify if the parity is correct for each segment of data.

#### Key Features:
- **Input:** A sequence of bits stored in an array, the length of the sequence, and the number of data bits (`n`).
- **Output:** Indicates whether there are errors in the parity bits (1 for errors, 0 for no errors).
- **Assembly Code:** The error-checking algorithm is implemented in assembly, iterating over the bit sequence and verifying the parity conditions.
- **Challenge:** Understanding bitwise operations and error detection techniques used in data communication and memory systems.

#### Code:
```c
#include <stdio.h>

void main() {
    unsigned char vet[] = { 0x7B,0xB0,0xBB,0xD3,0xC0,0xD2,0xD3,0x18,0xBB,0x4F,0x29,0x62 };
    unsigned int len = 55; 
    unsigned char n = 4; 

    unsigned char errori = 0;

    __asm {
        // Assembly code for error detection
    }

    printf("La sequenza di bit %scontiene errori\n", (errori ? "" : "non "));
}
```