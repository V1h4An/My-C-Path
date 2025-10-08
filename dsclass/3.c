/*Define the Person structure again. Write a function that dynamically 
allocates memory for a Person structure, initializes its fields with 
user input, and returns the pointer to the structure*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float height;
} Person;

Person* createPerson(const char* name, int age, float height) {
    Person *p = (Person *)malloc(sizeof(Person));
    strcpy(p->name, name);
    p->age = age;
    p->height = height;
    return p;
}

int main() {
    Person *p = createPerson("vihaan", 18, 177.50);
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Height: %.2f\n", p->height);
    free(p);
    return 0;
}