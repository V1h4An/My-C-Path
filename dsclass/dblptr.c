#include<stdio.h>
#include<stdlib.h>

/*void change_value(int* ptr,int n_val)
{
    printf("old val = %d\n",*ptr);
    *ptr = n_val;
return;
}

int main()
{
    int a = 10;
    int *b = &a;
    change_value(b,20);
    printf("new value = %d\n",a);
return 0;
}*/

/*what if you want to change the value of a pointer inside a function
You send the pointer to that pointer(double pointer)*/
void change_value(int **dblptr)
{
    int *x = (int*)malloc(sizeof(int));
    *x=40;
    *dblptr = x;
return ;
}

int main()
{
    int a=10;
    int *p = &a;
    int **q = &p;
    change_value(q);
    printf("new value = %d\n",**q);
  free(*q);
return 0;  
}