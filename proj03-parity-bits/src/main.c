#include <stdio.h>

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

void main()
{
    // Input
    unsigned char vet[] = {0x7B, 0xB0, 0xBB, 0xD3, 0xC0, 0xD2, 0xD3, 0x18, 0xBB, 0x4F, 0x29, 0x62};
    unsigned int len = 95; // Length in bits
    unsigned char n = 4;   // Number of data bits

    // Output
    unsigned char error_flag = 0; // 1 = errors found; 0 = no errors

    __asm {

        xor ecx, ecx // Reset bit sequence counter
        xor ebx, ebx // Reset data bit counter
        xor eax, eax // Reset byte accumulator

        mov ecx, len // Load total bit length
        mov bl, n // Load the number of data bits in bl
        xor edx, edx // Reset data bit counter
        xor esi, esi // Reset array index
        xor edi, edi // Reset error counter

    begin_sequence_check:
        cmp ecx, 0 // Check if we've reached the end of the sequence
        je finish_check

        mov al, vet[esi] // Load the current byte from the array
        mov bh, 8 // Reset bit counter for the byte
    process_byte:
        inc dl // Increment data bit counter
        shr al, 1 // Shift to read the least significant bit
        jc update_parity // If bit is 1, update parity
        jmp evaluate_counter // Otherwise, continue

    update_parity:
        xor dh, 1 // Toggle parity bit

    evaluate_counter:
        cmp dl, bl // Compare counter with n
        jne next_sequence // If not equal, continue

        dec ecx // Decrease remaining bits
        dec bh // Decrease bits in the byte

        xor dl, dl // Reset data bit counter
        cmp bh, 0 // Check if all bits in the byte are read
        jne continue_byte
        inc esi // Move to next byte if current byte is fully processed
        mov bh, 8
        mov al, vet[esi]
        
    continue_byte:
        mov dl, al
        and dl, 01 // Extract parity bit
        cmp dh, dl // Compare with calculated parity
        jne detected_error // If parity mismatch, go to error

        shr al, 1 // Remove parity bit from current byte
        xor dl, dl
        xor dh, dh
        jmp next_sequence // Continue sequence

    detected_error:
        inc edi // Increment error counter
        jmp finish_check // Exit after finding an error

    next_sequence:
        dec ecx // Decrement sequence length counter
        cmp ecx, 0 // Check if sequence is finished
        je finish_check

        dec bh // Decrement byte bit counter
        jnz process_byte // If byte has bits remaining, read next bit
        inc esi // Otherwise, move to next byte
        jmp begin_sequence_check

    finish_check:
        cmp edi, 0 // Check for errors
        je end_asm // If no errors, end
        mov error_flag, 1 // Otherwise, set error_flag to 1

    end_asm:
    }

    // Output result
    printf("The bit sequence %scontains errors\n", (error_flag ? "" : "does not "));
}
