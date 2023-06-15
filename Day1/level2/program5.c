/*Write a function to find the type of the character passed
    - 'A' to 'Z', return 1
    - 'a; to 'z', return 2
    - '0' to '9', return 3
    - Any Other printable symbols, return 4
    - Non printable symbols, return 5 */

    

#include <stdio.h>

int findCharacterType(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return 1;
    } else if (ch >= 'a' && ch <= 'z') {
        return 2;
    } else if (ch >= '0' && ch <= '9') {
        return 3;
    } else if (ch >= 32 && ch <= 126) {
        return 4;
    } else {
        return 5;
    }
}

int main() {
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);

    int type = findCharacterType(ch);
    switch (type) {
        case 1:
            printf("Character type: Uppercase letter\n");
            break;
        case 2:
            printf("Character type: Lowercase letter\n");
            break;
        case 3:
            printf("Character type: Digit\n");
            break;
        case 4:
            printf("Character type: Printable symbol\n");
            break;
        case 5:
            printf("Character type: Non-printable symbol\n");
            break;
        default:
            printf("Invalid character\n");
    }

    return 0;
}
