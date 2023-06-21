/*Write a function to initialize all members in the above array of structures*/




#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeArray(struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        students[i].rollno = 0;
        strcpy(students[i].name, "");
        students[i].marks = 0.0;
    }
}

int main() {
    // User-defined size of the array
    int size = 5;

    // Allocate memory for the array of structures
    struct Student* students = malloc(size * sizeof(struct Student));

    // Initialize the array of structures
    initializeArray(students, size);

    // Print the values of the initialized structures
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    // Free the allocated memory
    free(students);

    return 0;
}

