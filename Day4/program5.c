/*Diff between even & odd indexed elements*/



#include <stdio.h>

int main() {
    int size, i;
    int evenIndexSum = 0, oddIndexSum = 0;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int array[size];
    
    printf("Enter elements in the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
        
        // Check if the index is even or odd
        if (i % 2 == 0) {
            evenIndexSum += array[i];
        } else {
            oddIndexSum += array[i];
        }
    }
    
    int difference = evenIndexSum - oddIndexSum;
    
    printf("Sum of elements at even indices: %d\n", evenIndexSum);
    printf("Sum of elements at odd indices: %d\n", oddIndexSum);
    printf("Difference between even and odd indexed elements: %d\n", difference);
    
    return 0;
}
