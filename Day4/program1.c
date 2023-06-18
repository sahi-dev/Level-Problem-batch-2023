/*Sum & Average of 1D Array*/



#include <stdio.h>

int main() {
    int size, i;
    float sum = 0, average;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int array[size];
    
    printf("Enter elements in the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
        sum += array[i];
    }
    
    average = sum / size;
    
    printf("Sum of array elements: %.2f\n", sum);
    printf("Average of array elements: %.2f\n", average);
    
    return 0;
}
