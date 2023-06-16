/*Find the largest number by deleting single digit in a 4 digit number 5872 - 872, 9856 - 986

Concepts to be used.
- Loops
- Operators*/



#include <stdio.h>

int main() {
    int num, temp, digit, max = 0;
    
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);
    
    temp = num;
    
    for (int i = 0; i < 4; i++) {
        temp = num;
        int divisor = 1;
        
        for (int j = 0; j < i; j++) {
            divisor *= 10;
        }
        
        temp /= divisor * 10;
        temp = temp * divisor + (num % divisor);
        
        if (temp > max)
            max = temp;
    }
    
    printf("The largest number after deleting a single digit: %d\n", max);
    
    return 0;
}
