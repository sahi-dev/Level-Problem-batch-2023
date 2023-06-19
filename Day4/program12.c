/*Convert String as Integer*/



// #include <stdio.h>

// unsigned long djb2_hash(const char *str) {
//     unsigned long hash = 5381;
//     int c;

//     while ((c = *str++)) {
//         hash = ((hash << 5) + hash) + c;
//     }

//     return hash;
// }

// int main() {
//     char str[100];

//     printf("Enter a string: ");
//     scanf("%s", str);

//     unsigned long hash = djb2_hash(str);

//     printf("String: %s\n", str);
//     printf("Hash: %lu\n", hash);

//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[100];  // Assuming a maximum input length of 100 characters

    printf("Enter a string: ");
    scanf("%s", str);

    int num = atoi(str);

    printf("String: %s\n", str);
    printf("Integer: %d\n", num);

    return 0;
}



