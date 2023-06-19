/*Linear Search*/



#include <stdio.h>

int linearSearch(int array[], int size, int key) {
    int i;
    
    for (i = 0; i < size; i++) {
        if (array[i] == key) {
            return i;
        }
    }
    
    return -1;
}

int main() {
    int size, i, key, index;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int array[size];
    
    printf("Enter elements in the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    
    printf("Enter the element to search: ");
    scanf("%d", &key);
    
    index = linearSearch(array, size, key);
    
    if (index != -1) {
        printf("Element found at index %d.\n", index);
    } else {
        printf("Element not found.\n");
    }
    
    return 0;
}
