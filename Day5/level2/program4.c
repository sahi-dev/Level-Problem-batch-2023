/*Write a program to pass a pointer to a structure as a parameter to a function and return back a pointer to structure 
   to the calling function after modifying the members of structure.*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

struct Person* modifyPerson(struct Person* person) {
    printf("Enter the new name: ");
    scanf("%s", person->name);
    printf("Enter the new age: ");
    scanf("%d", &(person->age));

    return person;
}

int main() {
    struct Person person;

    printf("Enter the name: ");
    scanf("%s", person.name);
    printf("Enter the age: ");
    scanf("%d", &(person.age));

    struct Person* modifiedPerson = modifyPerson(&person);

    printf("\nModified Person:\n");
    printf("Name: %s\n", modifiedPerson->name);
    printf("Age: %d\n", modifiedPerson->age);

    return 0;
}