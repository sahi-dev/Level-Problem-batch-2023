/*Convert String as Integer*/



#include <stdio.h>

unsigned long djb2_hash(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    unsigned long hash = djb2_hash(str);

    printf("String: %s\n", str);
    printf("Hash: %lu\n", hash);

    return 0;
}
