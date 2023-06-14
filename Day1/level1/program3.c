/*Write a program to read the 
    - Roll No
    - Name (Note, you should read full name of the student including initials)
    - Marks of Physics, Math and Chemistry
    Calculate the total, percentage and print the summary.*/


#include <stdio.h>

int main() {
    int rollNo;
    char name[50];
    float physics, math, chemistry;
    float totalMarks, percentage;

    // Read student details
    printf("Enter Roll No: ");
    scanf("%d", &rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]s", name);

    printf("Enter Marks in Physics: ");
    scanf("%f", &physics);

    printf("Enter Marks in Math: ");
    scanf("%f", &math);

    printf("Enter Marks in Chemistry: ");
    scanf("%f", &chemistry);

    // Calculate total marks and percentage
    totalMarks = physics + math + chemistry;
    percentage = (totalMarks / 300) * 100;

    // Print summary
    printf("\nStudent Summary\n");
    printf("Roll No: %d\n", rollNo);
    printf("Name: %s\n", name);
    printf("Physics Marks: %.2f\n", physics);
    printf("Math Marks: %.2f\n", math);
    printf("Chemistry Marks: %.2f\n", chemistry);
    printf("Total Marks: %.2f\n", totalMarks);
    printf("Percentage: %.2f%%\n", percentage);

    return 0;
}
