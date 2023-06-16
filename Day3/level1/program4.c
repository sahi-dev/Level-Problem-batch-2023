/*Write a program to find both smallest and largest digits in given n numbers
For example let's say we have n = 3, and n1 = 8, n2 = 156, n3 = 123450, the result will be "Not Valid", 1 and 6, 0 and 5*/



#include <stdio.h>

void findSmallestAndLargestDigits(int n, int numbers[]) {
    int smallest = 9;  // Initialize smallest as the maximum possible digit
    int largest = 0;   // Initialize largest as the minimum possible digit

    for (int i = 0; i < n; i++) {
        int currentNum = numbers[i];
        while (currentNum > 0) {
            int digit = currentNum % 10;  // Extract the last digit
            if (digit < smallest)
                smallest = digit;
            if (digit > largest)
                largest = digit;
            currentNum /= 10;  // Remove the last digit
        }
    }

    if (smallest == 9 || largest == 0)
        printf("Not Valid\n");
    else
        printf("Smallest digit: %d\nLargest digit: %d\n", smallest, largest);
}

int main() {
    int n;
    printf("Enter the number of inputs: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Not Valid\n");
        return 0;
    }

    int numbers[n];
    printf("Enter the numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    findSmallestAndLargestDigits(n, numbers);

    return 0;
}
