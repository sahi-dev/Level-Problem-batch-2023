/*Diff between even & odd elements*/



#include <stdio.h>

int main() {
    int size, i;
    int evenSum = 0, oddSum = 0;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int array[size];
    
    printf("Enter elements in the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
        
        if (array[i] % 2 == 0) {
            evenSum += array[i];
        } else {
            oddSum += array[i];
        }
    }
    
    int difference = evenSum - oddSum;
    
    printf("Sum of even elements: %d\n", evenSum);
    printf("Sum of odd elements: %d\n", oddSum);
    printf("Difference between even and odd elements: %d\n", difference);
    
    return 0;
}
