/*1. Define a structure Person with name (string), age (integer), and height (float).
 Create a function that takes a Person structure as an argument and prints its details.*/
#include <stdio.h>

typedef struct 
{
   char name[100];
   int age;
   float height; 
} person ;

int print(person a)
{
    printf("%s\n",a.name);
    printf("%d\n",a.age);
    printf("%f\n",a.height);
return 0;
}

int main()
{
    person a;
    printf("enter name of person ");
    scanf("%s",&a.name);
    printf("enter age of person ");
    scanf("%d",&a.age);
    printf("enter height of person ");
    scanf("%f",&a.height);
    print(a);
    return 0;                           
}