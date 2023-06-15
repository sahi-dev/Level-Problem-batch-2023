/*Write a program to encode any given string such that it gets converted into an unrecognizable form. 
Also write a decode function to get back the original string.*/


#include <stdio.h>
#include <string.h>

void encode(char *str) {
    int length = strlen(str);
    
    for (int i = 0; i < length; i++) {
        str[i] = str[i] + 1;
    }
}

void decode(char *str) {
    int length = strlen(str);
    
    for (int i = 0; i < length; i++) {
        str[i] = str[i] - 1;
    }
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove trailing newline character
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    
    // Encoding the string
    encode(str);
    printf("Encoded string: %s\n", str);
    
    // Decoding the string
    decode(str);
    printf("Decoded string: %s\n", str);
    
    return 0;
}
