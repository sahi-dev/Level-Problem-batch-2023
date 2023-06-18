// Binary/Octal/Hex to Decimal Conversion



#include <stdio.h>
#include <math.h>
#include <string.h>

int binaryToDecimal(long long binary) {
    int decimal = 0, i = 0, remainder;
    
    while (binary != 0) {
        remainder = binary % 10;
        binary = binary / 10;
        decimal += remainder * pow(2, i);
        i++;
    }
    
    return decimal;
}

int octalToDecimal(int octal) {
    int decimal = 0, i = 0, remainder;
    
    while (octal != 0) {
        remainder = octal % 10;
        octal = octal / 10;
        decimal += remainder * pow(8, i);
        i++;
    }
    
    return decimal;
}

int hexadecimalToDecimal(char hexadecimal[]) {
    int decimal = 0, i, value, length;
    
    length = strlen(hexadecimal);
    for (i = 0; i < length; i++) {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            value = hexadecimal[i] - '0';
        } else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            value = hexadecimal[i] - 'A' + 10;
        } else if (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f') {
            value = hexadecimal[i] - 'a' + 10;
        } else {
            printf("Invalid hexadecimal number.\n");
            return -1; // Return -1 to indicate an error
        }
        
        decimal += value * pow(16, length - 1 - i);
    }
    
    return decimal;
}

int main() {
    int option;
    long long binary;
    int octal;
    char hexadecimal[32];
    
    printf("Conversion Options:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Octal to Decimal\n");
    printf("3. Hexadecimal to Decimal\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &option);
    
    switch (option) {
        case 1:
            printf("Enter a binary number: ");
            scanf("%lld", &binary);
            printf("Decimal equivalent: %d\n", binaryToDecimal(binary));
            break;
        case 2:
            printf("Enter an octal number: ");
            scanf("%d", &octal);
            printf("Decimal equivalent: %d\n", octalToDecimal(octal));
            break;
        case 3:
            printf("Enter a hexadecimal number: ");
            scanf("%s", hexadecimal);
            printf("Decimal equivalent: %d\n", hexadecimalToDecimal(hexadecimal));
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    
    return 0;
}
