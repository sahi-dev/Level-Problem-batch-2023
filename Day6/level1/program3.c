/*Write a function to display all members in the above array of structures*/




#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void displayArray(const struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    // User-defined size of the array
    int size = 5;

    // Allocate memory for the array of structures
    struct Student* students = malloc(size * sizeof(struct Student));

    // Initialize the array of structures (for demonstration purposes)
    for (int i = 0; i < size; i++) {
        students[i].rollno = i + 1;
        snprintf(students[i].name, sizeof(students[i].name), "Student %d", i + 1);
        students[i].marks = 75.0 + i * 5.0;
    }

    // Display all members in the array of structures
    displayArray(students, size);

    // Free the allocated memory
    free(students);

    return 0;
}
