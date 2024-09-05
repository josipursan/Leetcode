#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

/*
    Function is given : 
        -integer array (nums)
        -integer (k)
        -integer (multiplier)

    k operations need to be performed on nums array
    
    In each iteration:
        -find min value in nums (if there are multiple occurences, select the one tha appears first)
        -replace the found min value with x*multiplier

    After k operations, apply modulo operation to every value in nums array : 
        nums[i] % (10^9+7)

    Return integer array after all above described operations are executed

*/

int print_nums_arr(const uint64_t *nums, int numsSize)
{
    for(int i=0; i<numsSize; i++)
    {
        printf("%d : %ld\n", i, nums[i]);
    }
}

int findMin(uint64_t *nums, int numsSize)
{
    int i;
    int min_index = -1;
    uint32_t min_val = UINT32_MAX;

    for(i = 0; i<numsSize; i++)
    {
        if(nums[i] < min_val)
        {
            min_val = nums[i];
            min_index = i;
        }
    }
    return min_index;
}

// What's the point of *returnSize argument?
int *getFinalState(int *nums, int numsSize, int k, int multiplier, int *returnSize)
{
    int i;

    uint64_t *local_nums = malloc(numsSize * sizeof(uint64_t));
    for(i = 0; i<numsSize; i++)
    {
        *(local_nums+i) = nums[i];
    }
    
    print_nums_arr(local_nums, numsSize);

   for(i = 0; i<k; i++)    // k operations loop
    {
        int min_index = findMin(local_nums, numsSize);
        printf("k = %d\tmin index : %d\n", i, min_index);

        printf("i_%d before multiplication : %ld\n", i, *(local_nums+min_index));
        *(local_nums+min_index) = local_nums[min_index] * multiplier;
        printf("i_%d after multiplication : %ld\n", i, *(local_nums+min_index));
        print_nums_arr(local_nums, numsSize);
        printf("\n============\n");
    }

    int modulo_val = (int)pow((double)10, (double)9) + (double)7;
    printf("modulo_val : %d\n", modulo_val);

    int *retArr = malloc(numsSize * sizeof(int));

    for(i = 0; i<numsSize; i++)
    {
        retArr[i] = local_nums[i] % modulo_val;
    }
    print_nums_arr(local_nums, numsSize);
    free(local_nums);
    return retArr;
}

int main()
{
    //int nums[2] = {100000,2000};
    int nums[5] = {2,1,3,5,6};
    int size = 5;
    int k_loops = 5;
    int multiplier = 2;
    int retSz = -1;

    int *retPtr = getFinalState(nums, size, k_loops, multiplier, &retSz);
    printf("End res : \n");
    for(int i = 0; i<size; i++)
    {
        printf("%d : %d\n", i, retPtr[i]);
    }
    return 0;
}