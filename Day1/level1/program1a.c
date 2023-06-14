//Write a function to find biggest of 2 numbers using - if else

#include <stdio.h>

int findLargest(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

int main() {
    int a, b, largest;
    
    printf("Enter the first number: ");
    scanf("%d", &a);
    
    printf("Enter the second number: ");
    scanf("%d", &b);
    
    largest = findLargest(a, b);
    printf("The largest number is: %d\n", largest);
    
    return 0;
}
