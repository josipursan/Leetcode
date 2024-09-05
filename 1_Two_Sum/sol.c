#include <stdio.h>
#include <stdlib.h>

int *two_sum_1(int *nums_arr, int num_arr_length, int *target)  // This solution searches only for neighbouring numbers whose addition would give us *target.
{
    int *indices = NULL;
    int i;

    printf("num_arr_length : %d\n", num_arr_length);

    printf("target : %d\n", *target);

    for(i = 0; i<num_arr_length; i++)
    {
        if(((i+1) < num_arr_length))
        {
            printf("%d + %d = %d\n", *(nums_arr+i), *(nums_arr+i+1), *(nums_arr+i)+*(nums_arr+i+1));
            //printf("i : %d\n", i);
            if(((*(nums_arr+i)) + (*(nums_arr+i+1))) == *target)
            {
                printf("Ay yo, we found indices whose sum matches the target you sent!\n");
                printf("index %d val : %d\nindex %d val : %d\n", i, *(nums_arr+i), i+1, *(nums_arr+i+1));
                indices = (int*)malloc(2*sizeof(int));
                if(indices == NULL)
                {
                    printf("indices malloc issue\n");
                    exit(-1);
                }
                indices[0] = i;
                indices[1] = i+1;
                // ...or, you can use the below notation. But arr[] is visually nicer.
                //*indices=i;
                //*(indices+1)=i+1;

                printf("addr 1 : %x\naddr 2 : %x\n", &indices[0], &indices[1]);
                return indices;
            }
        }
    }
    return indices;
}

int *two_sum_2(int *nums_arr, int num_arr_length, int *target)  // This function searches the whole array for two numbers which would give us an addition result equal to *target, ie. numbers for addition DO NOT have to be neighbours such as in two_sum_1() function.
{
    int *indices = NULL;
    int i,j;

    printf("num_arr_length : %d\n", num_arr_length);

    printf("target : %d\n", *target);

    for(i = 0; i<num_arr_length; i++)
    {
        for(j = 0; j<num_arr_length; j++)
        {
            if(j == i)
            {
                continue;   // The leetcode problem has set a condition : "you may not use the same element twice"; therefore, if i and j loops are looking at the same arr element, continue
            }
            printf("%d + %d = %d\n", *(nums_arr+i), *(nums_arr+j), *(nums_arr+i)+*(nums_arr+j));
            //printf("i : %d\n", i);
            if(((*(nums_arr+i)) + (*(nums_arr+j))) == *target)
            {
                printf("Ay yo, we found indices whose sum matches the target you sent!\n");
                printf("index %d val : %d\nindex %d val : %d\n", i, *(nums_arr+i), j, *(nums_arr+j));
                indices = (int*)malloc(2*sizeof(int));
                if(indices == NULL)
                {
                    printf("indices malloc issue\n");
                    exit(-1);
                }
                indices[0] = i;
                indices[1] = j;
                // ...or, you can use the below notation. But arr[] is visually nicer.
                //*indices=i;
                //*(indices+1)=j;

                printf("addr 1 : %x\naddr 2 : %x\n", &indices[0], &indices[1]);
                return indices;
            }
        }
    }
    return indices;
}

int main()
{
    int nums[7] = {4,2,8,9,58,102,1};

    int target = 59;

    int *res = two_sum_2(nums, 7, &target);
    if(res == NULL)
    {
        printf("No indices found!\n");
        return -1;
    }
    printf("\nRes pointer in main :\nvalue %d\nvalue %d\n", res[0], res[1]);
    printf("addr 1 : %x\naddr 2 : %x\n", &res[0], &res[1]);
    free(res);
    return 0;
}