/* Implement structures to read, write and compute average- marks and the students scoring above
   and below the average marks for a class of N students.*/




#include <stdio.h>

#define MAX_STUDENTS 50

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

void readStudent(struct Student* student) {
    printf("Enter student name: ");
    scanf("%s", student->name);
    printf("Enter student roll number: ");
    scanf("%d", &(student->rollNumber));
    printf("Enter student marks: ");
    scanf("%f", &(student->marks));
}

void writeStudent(struct Student student) {
    printf("Name: %s\n", student.name);
    printf("Roll Number: %d\n", student.rollNumber);
    printf("Marks: %.2f\n", student.marks);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    for (int i = 0; i < numStudents; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        readStudent(&students[i]);
    }

    float totalMarks = 0;
    for (int i = 0; i < numStudents; i++) {
        totalMarks += students[i].marks;
    }
    float averageMarks = totalMarks / numStudents;

    printf("\nAverage marks: %.2f\n", averageMarks);

    printf("\nStudents scoring above average marks:\n");
    for (int i = 0; i < numStudents; i++) {
        if (students[i].marks > averageMarks) {
            writeStudent(students[i]);
        }
    }

    printf("\nStudents scoring below average marks:\n");
    for (int i = 0; i < numStudents; i++) {
        if (students[i].marks < averageMarks) {
            writeStudent(students[i]);
        }
    }

    return 0;
}
