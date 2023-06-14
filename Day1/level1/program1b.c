//Write a function to find biggest of 2 numbers using - ternary operator

#include <stdio.h>

int findLargest(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
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
