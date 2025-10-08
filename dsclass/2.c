/*Define the same Person structure. Create a function that takes
a pointer to a Personstructure and updates the age and height
fields.*/
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


int uprint(person a)
{
    printf("%d\n",a.age);
    printf("%f\n",a.height);
return 0;
}

void update(person *a,int age,float height)
{
    a->age = age;
    a->height = height;
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
    printf("enter updated age of person ");
    scanf("%d",&a.age);
    printf("enter updated height of person ");
    scanf("%f",&a.height);
    uprint(a);
    return 0;                           
}