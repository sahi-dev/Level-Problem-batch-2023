/*Assume User will be providing input in the form of a string as show below. 
Write a function to parse the string and initialize an array of structures. 

Example String : "1001 Aron 100.00" 
Example Structure : 
    struct Student{
        int rollno;
        char name[20];
        float marks;
    };

Note: User must be able define the no. of inputs/size of the array during runtime.*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char* input, struct Student* students, int size) {
    char* token;
    int count = 0;

    char buffer[strlen(input) + 1];
    strcpy(buffer, input);

    token = strtok(buffer, " ");
    while (token != NULL && count < size) {
        students[count].rollno = atoi(token);

        token = strtok(NULL, " ");
        if (token == NULL) break;
        strncpy(students[count].name, token, sizeof(students[count].name) - 1);
        students[count].name[sizeof(students[count].name) - 1] = '\0';

        token = strtok(NULL, " ");
        if (token == NULL) break;
        students[count].marks = atof(token);

        count++;
        token = strtok(NULL, " ");
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar();

    struct Student* students = malloc(size * sizeof(struct Student));

    char input[100];
    printf("Enter the student data: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    parseString(input, students, size);

    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    free(students);
    return 0;
}
