/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>


int* twoSum(int* nums, int numsSize, int target)
{
    for(int i=0;i<numsSize;i++)
    {
        for(int j = 0;i<numsSize;j++)
        {
            if(nums[i]!=nums[j] && nums[i]+ nums[j]==target)
            {
                int *result =(int*)malloc(2*sizeof(int));
                result[0]=nums[i];
                result[1]=nums[j];
                return result;
            }
        }
    }
    return NULL;
}

int main()
{
    int numsSize;
    printf("enter size of array");
    scanf("%d", &numsSize);
    int nums[numsSize];
    printf("enter elements of array");
    for(int j=0;j<numsSize;j++)
    {
        scanf("%d",&nums[j]);
    }
    int target;
    printf("enter target number");
    scanf("%d",&target);
    int *result =twoSum(nums,numsSize,target);
    if(result !=NULL)
    {
        printf("%d + %d gives target", result[0],result[1]);
        free(result);
    }
    else
    {
        printf("two number sum of target doesnot exist");
    }
return 0;
}