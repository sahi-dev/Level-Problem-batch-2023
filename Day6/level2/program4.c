/* Write a function to rotate the above array of structures by K positions*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void rotateArray(struct Student* students, int size, int k) {
    struct Student* temp = malloc(k * sizeof(struct Student));

    memcpy(temp, &students[size - k], k * sizeof(struct Student));

    memmove(&students[k], students, (size - k) * sizeof(struct Student));

    memcpy(students, temp, k * sizeof(struct Student));

    free(temp);
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

    int k;
    printf("\nEnter the number of positions to rotate: ");
    scanf("%d", &k);

    rotateArray(students, size, k);

    printf("\nUpdated array after rotation:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    free(students);

    return 0;
}
