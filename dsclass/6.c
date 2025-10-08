/*Define a structure Employee with name (string) and manager 
(pointer to another Employee structure). Write a program to create two 
employees where one is the manager of the other and print their 
details.*/

#include <stdio.h>
#include <string.h>

// Define the Employee structure
typedef struct Employee {
    char name[50];
    struct Employee *manager;
};

int main() {
    // Create two Employee instances
    struct Employee manager;
    struct Employee employee;

    // Set the manager's details
    strcpy(manager.name, "Alice");
    manager.manager = NULL; // Alice has no manager

    // Set the employee's details
    strcpy(employee.name, "Bob");
    employee.manager = &manager; // Bob's manager is Alice

    // Print the details
    printf("Employee Name: %s\n", employee.name);
    if (employee.manager != NULL) {
        printf("Manager Name: %s\n", employee.manager->name);
    } else {
        printf("Manager: None\n");
    }

    return 0;
}