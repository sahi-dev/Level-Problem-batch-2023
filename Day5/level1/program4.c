/*write a program to Store Data for n students in Structures Dynamically. */




#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[100];
    int age;
    float marks;
};

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student* students = (struct Student*)malloc(n * sizeof(struct Student));

    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Enter the name: ");
        scanf(" %[^\n]s", students[i].name);

        printf("Enter the age: ");
        scanf("%d", &(students[i].age));

        printf("Enter the marks: ");
        scanf("%f", &(students[i].marks));
    }

    printf("\nStudent Details:\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2f\n", students[i].marks);
    }

    free(students);

    return 0;
}
