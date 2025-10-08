#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
        printf("enter the number of values to be stored");
        scanf("%d",&n);
    int* ptr;
    ptr = (int*)malloc(n*sizeof(int));

            if(ptr == NULL)
            {
                printf("memory failed to allocate");
                return 0;   
            }

        printf("enter the values to be stored");
            for(i=0;i<n;i++)
            {
                scanf("%d",&ptr +i);
            }
        printf("values stored are");
            for(i=0;i<n;i++)    
            {
                printf("%d\n",*(ptr+i));
            }
        free(ptr);
return 0;
}
