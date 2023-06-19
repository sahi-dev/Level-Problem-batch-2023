/*Toggle Case*/



#include <stdio.h>

void toggleCase(char str[]) {
    int i = 0;
    
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            // Converts lowercase to uppercase
            str[i] = str[i] - 32;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            // Converts uppercase to lowercase
            str[i] = str[i] + 32;
        }
        
        i++;
    }
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    toggleCase(str);
    printf("Toggled case string: %s\n", str);
    
    return 0;
}
