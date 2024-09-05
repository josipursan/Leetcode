#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    double medianValue = 0;
    int *tempArr = malloc(sizeof(int) * (nums1Size+nums2Size));

    int i,j;

    if(tempArr == NULL)
    {
        printf("failed malloc");
        exit(-1);
    }

    memcpy(tempArr, nums1, nums1Size*sizeof(int));
    memcpy(tempArr + nums1Size, nums2, nums2Size*sizeof(int));

    for(i = 0; i<nums1Size+nums2Size; i++)
    {
        printf("%d : %d\n", i, *(tempArr+i));
    }

    for(i = 0; i<nums1Size+nums2Size; i++)
    {
        for(j = i; j<nums1Size+nums2Size; j++)
        {
            int temp_var = -1;
            if(tempArr[i] > tempArr[j])
            {
                temp_var = tempArr[i];
                tempArr[i] = tempArr[j];
                tempArr[j] = temp_var;
            }
        }
    }
    for(i = 0; i<nums1Size+nums2Size; i++)
    {
        printf("%d : %d\n", i, *(tempArr+i));
    }

    if((nums1Size+nums2Size)%2 == 0)
    {
        medianValue = ((double)tempArr[((nums1Size+nums2Size)/2)-1] + (double)tempArr[((nums1Size+nums2Size)/2)])/2    ;
    }
    else
    {
        medianValue = (double)tempArr[((nums1Size+nums2Size)/2)];
    }

    return medianValue;
}


int main()
{
    int nums1[2] = {1,3};
    int nums2[1] = {2};

    double retVal = findMedianSortedArrays(nums1, 2, nums2, 1);
    printf("Median is : %f\n", retVal);

    return 0;
}