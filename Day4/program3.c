/*Reverse The Array*/



#include <stdio.h>

int main() {
    int size, i, temp;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int array[size];
    
    printf("Enter elements in the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    
    for (i = 0; i < size / 2; i++) {
        temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
    
    printf("Reversed array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    
    return 0;
}
