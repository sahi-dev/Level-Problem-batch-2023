/*Write a function to return the grade of the given student using switch case statements
90 to 100 -> 'A'
75 to 89 -> 'B'
60 to 74 -> 'C'
50 to 59 -> 'D'
36 to 49 -> 'E'
0 to 35 -> 'F'

In main check the return value and print the below
65 -> "Grade A"
66 -> "Grade B"
67 -> "Grade C"
68 -> "Grade D"
69 -> "Grade E"
70 -> "Grade F"*/


#include <stdio.h>

char getGrade(int score) {
    char grade;

    if (score >= 90 && score <= 100) {
        grade = 'A';
    } else if (score >= 75 && score <= 89) {
        grade = 'B';
    } else if (score >= 60 && score <= 74) {
        grade = 'C';
    } else if (score >= 50 && score <= 59) {
        grade = 'D';
    } else if (score >= 36 && score <= 49) {
        grade = 'E';
    } else if (score >= 0 && score <= 35) {
        grade = 'F';
    } else {
        grade = 'N'; // Invalid grade
    }

    return grade;
}

int main() {
    int score;

    printf("Enter the student's score: ");
    scanf("%d", &score);

    char grade = getGrade(score);

    switch(grade) {
        case 'A':
            printf("Grade A\n");
            break;
        case 'B':
            printf("Grade B\n");
            break;
        case 'C':
            printf("Grade C\n");
            break;
        case 'D':
            printf("Grade D\n");
            break;
        case 'E':
            printf("Grade E\n");
            break;
        case 'F':
            printf("Grade F\n");
            break;
        default:
            printf("Invalid score\n");
    }

    return 0;
}

