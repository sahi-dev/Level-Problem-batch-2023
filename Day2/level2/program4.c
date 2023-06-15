/*Write a function xstrchr() which scans a string from beginning to end in search of a character. 
If the character is found, it should return a pointer to the first occurrence of the given character in the string.
If the given character is not found, the function returns a NULL.
The prototype of the function should be:

char *xstrchr(char *string, char ch):*/



#include <stdio.h>

char *xstrchr(char *string, char ch) {
    while (*string != '\0') {
        if (*string == ch) {
            return string; 
        }
        string++;  
    }
    
    return NULL;  
}

int main() {
    char str[100];
    char ch;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    printf("Enter a character to search for: ");
    scanf("%c", &ch);
    
    char *result = xstrchr(str, ch);
    if (result != NULL) {
        printf("Character '%c' found at position %ld\n", ch, result - str);
    } else {
        printf("Character '%c' not found\n", ch);
    }
    
    return 0;
}
