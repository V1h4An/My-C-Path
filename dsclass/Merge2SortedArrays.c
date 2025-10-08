/*Write a program that takes two sorted arrays of integers and merges 
them into a single sorted array. Ensure your solution handles arrays 
of different lengths and merges the arrays in O(n) time complexity, 
where n is the total number of elements in both arrays.*/

#include<stdio.h>
#include<stdlib.h>

void sorting(int *arr,int size)
{
    for(int i=0;i<size-1;i++)
        for(int j= 0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp  = arr[j];
                arr[j]   = arr[j+1];
                arr[j+1] = temp;
            }
        }
}

void merge(int *arr1,int *arr2,int size1,int size2)
{   
    int c=0;
    int size = size1+size2;
    int *arr = (int*)malloc(size*sizeof(int));
    
    for(int i=0;i<size1;i++)   
        {
            arr[c++] = arr1[i];
        }
    
        for(int j=0;j<size2;j++)
        {
            arr[c++] = arr2[j];
        }
    
    printf("\narray after merging is\n");
    
    for(int x=0;x<size;x++)
        {
        printf("%d\t",arr[x]);
        }
    
    sorting(arr,size); 
    
    printf("\narray after final sort is\n");
    
    for(int i=0;i<size;i++)
        {
        printf("%d\t",arr[i]);
        }

}

int main()
{
int arr1[] ={3,7,5,4,2};
int size1 = sizeof(arr1)/sizeof(arr1[0]);
int arr2[] ={9,1,8,6,10};
int size2 = sizeof(arr2)/sizeof(arr2[0]);
    
printf("arrays before sorting are\n");
    
    for(int i=0;i<size1;i++)
        {
        printf("%d\t",arr1[i]);
        }
    
    printf("\n");
    
    for(int i=0;i<size2;i++)
        {
        printf("%d\t",arr2[i]);
        }
    printf("\n");

sorting(arr1,size1);
    
    printf("array 1 after sorting :\n");
        for(int i=0;i<size1;i++)
        {
            printf("%d\t",arr1[i]);
        }
    printf("\n");

sorting(arr2,size2);
    
    printf("array 2 after sorting :\n");  
        for(int i=0;i<size2;i++)
        {
            printf("%d\t",arr2[i]);
        }

merge(arr1,arr2,size1,size2);

return 0;
}
