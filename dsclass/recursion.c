#include <stdio.h>
#include <limits.h>

int largest(int arr[],int n)
{
    if(n==1)
    {
    return arr[0];
    }
int max = largest(arr,n-1);
    if(arr[n-1]>max)
    {
        return arr[n-1];
    }
    else
    {
        return max;
    }
    }


int smallest(int arr[],int n)
{
    if(n==1)
    {
    return arr[0];
    }
int min = smallest(arr,n-1);
    if(arr[n-1]<min)
    {
        return arr[n-1];
    }
    else
    {
        return min;
    }
    }
    
    
int main()
{
int n;
    printf("enter size of array\t");
    scanf("%d",&n);
int arr[n];
    printf("enter elements of the array\t");

for(int i=0;i<n;i++)
{
    scanf("%d",&arr[i]);
}
    printf("entered array is\t\n\n");

for(int i=0;i<n;i++)
{
    printf("%d\t",arr[i]);
}
int lrg = largest(arr,n);
int sml = smallest(arr,n);

    printf("\n\n\tthe largest element is %d\t",lrg);
    printf("\n\n\tthe smallest element is %d\t",sml);
    
return 0;
}