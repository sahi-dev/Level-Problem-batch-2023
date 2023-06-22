/*Write a function to delete a member at the start of the above array of structures
Note : Code must use Dynamic Memory concept*/





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

struct Student* deleteMember(struct Student* students, int* size) {
    (*size)--;

    for (int i = 0; i < (*size); i++) {
        students[i] = students[i + 1];
    }

    students = realloc(students, (*size) * sizeof(struct Student));

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

    students = deleteMember(students, &size);

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