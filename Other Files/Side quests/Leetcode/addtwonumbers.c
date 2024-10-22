/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    int             flag = 0; // become 1 if the sum >= 10
    int             sum;
    struct ListNode *head;
    struct ListNode *newlist = malloc(sizeof(struct ListNode));

    if (!newlist)
        return (NULL);
    head = newlist;
    // Loop while both lists still exist
    while (l1 && l2)
    {
        newlist->val = malloc(sizeof(int)); // Need protection for all nodes
        sum = l1->val + l2->val + flag;
        if (sum >= 10)
        {
            flag = 1;
            sum = sum % 10;
        }
        else
            flag = 0;
        newlist->val = sum;
        newlist->next = malloc(sizeof(struct ListNode)); // Needs protection for all nodes
        newlist->next->next = NULL;
        newlist = newlist->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    // Loop while only l1 exists
    while (l1)
    {
        newlist->val = malloc(sizeof(int)); // Need protection for all nodes
        sum = l1->val + flag;
        if (sum >= 10)
        {
            flag = 1;
            sum = sum % 10;
        }
        else
            flag = 0;
        newlist->val = sum;
        newlist->next = malloc(sizeof(struct ListNode)); // Needs protection for all nodes
        newlist->next->next = NULL;
        newlist = newlist->next;
        l1 = l1->next;
    }
    // Loop while only l2 exists
    while (l2)
    {
        newlist->val = malloc(sizeof(int)); // Need protection for all nodes
        sum = l2->val + flag;
        if (sum >= 10)
        {
            flag = 1;
            sum = sum % 10;
        }
        else
            flag = 0;
        newlist->val = sum;
        newlist->next = malloc(sizeof(struct ListNode)); // Needs protection for all nodes
        newlist->next->next = NULL;
        newlist = newlist->next;
        l2 = l2->next;
    }
    // if flag is still 1 allocate memory for it and put in there
    if (flag == 1)
    {
        newlist->val = malloc(sizeof(int)); // Need protection for all nodes
        newlist->val = 1;
    }
    return (head);
}