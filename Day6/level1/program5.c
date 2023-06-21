/*Write a function to perform a search operation on the array of structures based on name of the student*/




#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

int searchByName(const struct Student* students, int size, const char* searchName) {
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);

    struct Student* students = malloc(size * sizeof(struct Student));

    for (int i = 0; i < size; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);

        printf("Roll No: ");
        scanf("%d", &students[i].rollno);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    char searchName[20];
    printf("\nEnter the name of the student to search: ");
    scanf("%s", searchName);

    int searchIndex = searchByName(students, size, searchName);

    if (searchIndex != -1) {
        printf("\nStudent found at index %d\n", searchIndex);
        printf("Roll No: %d\n", students[searchIndex].rollno);
        printf("Name: %s\n", students[searchIndex].name);
        printf("Marks: %.2f\n", students[searchIndex].marks);
    } else {
        printf("\nStudent not found.\n");
    }

    free(students);

    return 0;
}
