/*Write a program to swap any type of data passed to an function.

Topics to be covered
- Pointers
- Type Casting*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *a, void *b, size_t size) {
    char *temp = malloc(size);              // Allocate memory for temporary storage-Type casting
    memcpy(temp, a, size);                  // Copy value of 'a' to temporary storage
    memcpy(a, b, size);                     // Copy value of 'b' to 'a'
    memcpy(b, temp, size);                  // Copy value of temporary storage to 'b'
    free(temp);                             // Free the allocated memory
}

int main() {
    int num1, num2;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2, sizeof(int));
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}

