/*Suppose 7 names are stored in an array of pointers names[] as shown below:
 char *name[]={
        "Santosh", "Amol", "Santosh Jain", "Kishore", "Rahul", "Amolkumar", "Hemant"
          }
  Write a program to arrange these names in alphabetical order.*/



#include <stdio.h>
#include <string.h>

#define MAX_NAMES 7

int main() {
    char *names[] = {
        "Santosh", "Amol", "Santosh Jain", "Kishore", "Rahul", "Amolkumar", "Hemant"
    };

    int i, j;
    char *temp;

    // Bubble sort algorithm
    for (i = 0; i < MAX_NAMES - 1; i++) {
        for (j = 0; j < MAX_NAMES - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap the pointers
                temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }

    // Print the sorted names
    printf("Sorted names:\n");
    for (i = 0; i < MAX_NAMES; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}

