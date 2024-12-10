# Project 1: Sorting Array of String Pointers by ASCII Code

#### Description:
In this project, you are tasked with sorting an array of pointers to strings based on their ASCII values. Each string in the array is terminated by the null character (`\0`), and the program uses assembly code to sort the strings in ascending order.

#### Key Features:
- **Input:** Array of string pointers.
- **Output:** Sorted array of strings based on ASCII values.
- **Assembly Code:** The sorting algorithm is implemented in x86 assembly within a C program. The sorting routine uses registers and memory access instructions to perform the comparison and rearrangement of the string pointers.
- **Challenge:** Manipulating string pointers and performing sorting using assembly language.

#### Code:
```c
#include <stdio.h>
#include <string.h>

int main()
{
    char *strings[] = {"AAA", "aaa", "BBB", "bbb", "CCC", "ccc"};
    unsigned short num = sizeof(strings) / sizeof(strings[0]);

    __asm {
        // Assembly sorting logic here
    }

    for (int i = 0; i < num; i++)
        printf("%s\n", strings[i]);

    return 0;
}
