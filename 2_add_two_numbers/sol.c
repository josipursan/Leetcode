#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    You are given two non-empty linked lists.
    Each list represents two non-negative integers.
    Digis are stored in reverse. E.g. linked list has 3,5,7 in it. This linked list represents number 753.
    Add the two numbers (two linked lists) and return the sum as a linked list.
    The result also needs to be returned in reverse.

    Example
    l1 = [2,4,3]
    l2 = [5,6,4]

    342 + 465 = 807

    return_list = [7,0,8]

    =====================

    Constraints

        -number of nodes in each linked list is [1,100]
        -each node has val in range [0,9]
        -linked list representing a number DOES NOT have leading zeros
*/

struct ListNode
{
    int val;
    int *nextNode;
}ListNode;

struct LinkedList
{
    int size;

    int *head;
    int *tail;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *local_l1;
    struct ListNode *local_l2;
    struct ListNode *returnList;
    struct ListNode *ptrToCurrentLastNode=malloc(sizeof(struct ListNode));
    int summation = 0;

    ptrToCurrentLastNode->val = 0;
    ptrToCurrentLastNode->nextNode = NULL;

    returnList = ptrToCurrentLastNode;

    local_l1 = l1;
    local_l2 = l2;

    while(local_l1 || local_l2 || summation)
    {
        if(local_l1)
        {
            summation += local_l1->val;
            local_l1 = local_l1->nextNode;
        }
        if(local_l2)
        {
            summation += local_l2->val;
            local_l2 = local_l2->nextNode;
        }

        struct ListNode *nextNode = malloc(sizeof(struct ListNode));
        nextNode->val = summation%10;
        nextNode->nextNode = NULL;
        summation /= 10;

        if(returnList)
        {
            ptrToCurrentLastNode->nextNode=nextNode;
            ptrToCurrentLastNode = nextNode;
        }
    }
    return returnList->nextNode;
}

int main()
{
    struct ListNode *l1_n1 = malloc(sizeof(ListNode));
    struct ListNode *l1_n2 = malloc(sizeof(ListNode));
    struct ListNode *l1_n3 = malloc(sizeof(ListNode));
    struct ListNode *l1_n4 = malloc(sizeof(ListNode));

    struct ListNode *l2_n1 = malloc(sizeof(ListNode));
    struct ListNode *l2_n2 = malloc(sizeof(ListNode));
    struct ListNode *l2_n3 = malloc(sizeof(ListNode));

    l1_n1->val = 3;
    l1_n2->val = 5;
    l1_n3->val = 8;
    l1_n4->val = 4;
    l1_n1->nextNode = l1_n2;
    l1_n2->nextNode = l1_n3;
    l1_n3->nextNode = l1_n4;
    l1_n4->nextNode = NULL; // Last node points to NULL because there are no more nodes after it

    l2_n1->val = 9;
    l2_n2->val = 8;
    l2_n3->val = 1;
    l2_n1->nextNode = l2_n2;
    l2_n2->nextNode = l2_n3;
    l2_n3->nextNode = NULL;

    printf("l1_n1 : %x\nl1_n2 : %x\nl1_n3 : %x\nl1_n4 : %x\n\nl2_n1 : %x\nl2_n2 : %x\nl2_n3 : %x\n", l1_n1, l1_n2, l1_n3, l1_n4, l2_n1, l2_n2, l2_n3);
    printf("l1_n1 val : %x\nl1_n2 val : %x\nl1_n3 val : %x\n\nl2_n1 val : %x\nl2_n2 val : %x\nl2_n3 val : %x\n", l1_n1->val, l1_n2->val, l1_n3->val, l2_n1->val, l2_n2->val, l2_n3->val);
    printf("\nl1_n1->next : %x\nl1_n2->next : %x\nl1_n3->nextNode: %x\n\nl2_n1->next : %x\nl2_n2->next : %x\nl2_n3->next : %x\n\n\n", l1_n1->nextNode, l1_n2->nextNode, l1_n3->nextNode, l2_n1->nextNode, l2_n2->nextNode, l2_n3->nextNode);
    printf("==================================================================================\n\n");

    struct ListNode *returnedSum = addTwoNumbers(l1_n1, l2_n1);
    printf("returned sum 0 : %d\n", returnedSum->val);

    returnedSum = returnedSum->nextNode;
    printf("returned sum 0 : %d\n", returnedSum->val);
   
    returnedSum = returnedSum->nextNode;
    printf("returned sum 0 : %d\n", returnedSum->val);
    
    returnedSum = returnedSum->nextNode;
    printf("returned sum 0 : %d\n", returnedSum->val);

    return 0;
}