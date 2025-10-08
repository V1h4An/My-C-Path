# include <stdio.h>
void swap(int* a, int* b);

int main()
{
int x,y;
    printf("enter 2 numbers");
    scanf("%d",&x);
    scanf("%d",&y);
    printf("x before swap is %d\ny bnefore swap is %d\n",x,y);
swap(&x,&y);
    printf("x after swap is %d\ny after swap is %d",x,y);    
return 0;
}
void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}