/*Write a function to swap 2 members in different indexes (based on user input) in the above array of structures*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void swapMembers(struct Student* students, int index1, int index2) {
    struct Student temp = students[index1];
    students[index1] = students[index2];
    students[index2] = temp;
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

    int index1, index2;
    printf("\nEnter the indices of the members to swap (0 to %d): ", size - 1);
    scanf("%d %d", &index1, &index2);

    swapMembers(students, index1, index2);

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
