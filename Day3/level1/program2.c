/*Prints Bits:
Scan a 32bit integer and prints its bits.

Concepts to be used.
- Loops
- Bitwise Operators*/



#include <stdio.h>

void printBits(unsigned int num);

int main() {
    unsigned int num;
    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);
    printf("Bits: ");
    printBits(num);
    return 0;
}

void printBits(unsigned int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        unsigned int mask = 1u << i;
        unsigned int bit = (num & mask) ? 1 : 0;
        printf("%u", bit);
    }
    printf("\n");
}