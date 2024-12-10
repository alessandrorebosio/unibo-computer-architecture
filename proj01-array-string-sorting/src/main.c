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
		// Assembly sorting logic here
	}

	// Print the sorted strings to the screen
	for (int i = 0; i < num; i++)
		printf("%s\n", strings[i]);

	return 0;
}
