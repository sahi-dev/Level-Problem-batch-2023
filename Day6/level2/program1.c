/*Write a function to add a member at the end of the above array of structures
Note : Code must use Dynamic Memory concept*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

struct Student* addMember(struct Student* students, int* size) {
    (*size)++;

    students = realloc(students, (*size) * sizeof(struct Student));

    struct Student newMember;

    printf("\nEnter details for the new member:\n");

    printf("Roll No: ");
    scanf("%d", &newMember.rollno);

    printf("Name: ");
    scanf("%s", newMember.name);

    printf("Marks: ");
    scanf("%f", &newMember.marks);

    students[(*size) - 1] = newMember;

    return students;
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

    students = addMember(students, &size);

    printf("\nUpdated array:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    free(students);

    return 0;
}
