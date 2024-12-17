#include <stdio.h>
#include <string.h>

/********************************************************************************
 *                     Computer Systems Architecture                            *
 ********************************************************************************
 Project 1
 Description: Given an array of string pointers (each cell of the array contains
			  the 32-bit address of the first character of the string), sort it
			  according to ASCII code. Each string ends with the null character
			  (ASCII code 0).
 ********************************************************************************/

int main()
{
	// The strings to be sorted (array of pointers)
	char *strings[] = {"AAA", "aaa", "BBB", "bbb", "CCC", "ccc"};
	// Number of strings (unsigned short, 16 bits)
	unsigned short num = sizeof(strings) / sizeof(strings[0]);

	__asm {
        movzx edi, num; // Zero-extend num (16-bit) into edi (32-bit)

    outer_loop:
        dec edi; // edi = edi - 1
        jl end_sorting;

        xor esi, esi; // Reset the inner loop counter

    inner_loop:
        cmp esi, edi; // if (esi >= edi) jump to outer_loop
        jge check_next;

        mov ebx, dword ptr[strings + esi * 4]; // ebx = strings[esi]
        mov ecx, dword ptr[strings + esi * 4 + 4]; // ecx = strings[esi + 1]

        xor eax, eax; // Reset character comparison index
    
    compare_chars:
        mov dl, byte ptr[ebx + eax]; // dl = *ebx
        cmp dl, 0; // if (dl == 0) jump to end_compare
        jz end_compare;

        mov dh, byte ptr[ecx + eax]; // dh = *ecx
        cmp dh, 0; // if (dh == 0) jump to end_compare
        jz end_compare;

        inc eax; // Move to the next character

        cmp dl, dh; // if (dl == dh) jump to compare_chars, otherwise jump to end_compare
        je compare_chars;
        jl end_compare;

    end_compare:
        mov dword ptr[strings + esi * 4], ecx; // strings[esi] = ecx
        mov dword ptr[strings + esi * 4 + 4], ebx; // strings[esi + 1] = ebx

        inc esi; // Increment the inner loop counter
        jmp inner_loop; // Continue with the next string

    check_next:
        jmp outer_loop; // Continue with the next string in the outer loop

    end_sorting:
	}

	// Print the sorted strings to the screen
	for (int i = 0; i < num; i++)
		printf("%s\n", strings[i]);

	return 0;
}
