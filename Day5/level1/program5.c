/*Write a program to demonstrate the swapping the fields of two structures using pointers*/




#include <stdio.h>
#include <string.h>

struct Person {
    char name[100];
    int age;
};

void swapFields(struct Person* p1, struct Person* p2) {
    char tempName[100];
    strcpy(tempName, p1->name);
    strcpy(p1->name, p2->name);
    strcpy(p2->name, tempName);

    int tempAge = p1->age;
    p1->age = p2->age;
    p2->age = tempAge;
}

int main() {
    struct Person person1, person2;

    printf("Enter the name of Person 1: ");
    scanf("%[^\n]s", person1.name);
    printf("Enter the age of Person 1: ");
    scanf("%d", &person1.age);

    printf("Enter the name of Person 2: ");
    scanf("%s", person2.name);
    printf("Enter the age of Person 2: ");
    scanf("%d", &person2.age);

    printf("\nBefore swapping:\n");
    printf("Person 1: Name = %s, Age = %d\n", person1.name, person1.age);
    printf("Person 2: Name = %s, Age = %d\n", person2.name, person2.age);

    swapFields(&person1, &person2);

    printf("\nAfter swapping:\n");
    printf("Person 1: Name = %s, Age = %d\n", person1.name, person1.age);
    printf("Person 2: Name = %s, Age = %d\n", person2.name, person2.age);

    return 0;
}
