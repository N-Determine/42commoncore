#include <stdio.h>

struct ListNode 
{
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
{
    struct ListNode *tmp1 = list1;
	struct ListNode *tmp2 = list2;
	struct ListNode *save_head;
	
	struct ListNode *head;
    if (!tmp1)
        return (tmp2);
    if (!tmp2)
        return (tmp1);
    if (tmp1->val <= tmp2->val)
    {
        head = tmp1;
        tmp1 = tmp1->next;
    }
    else
    {
        head = tmp2;
        tmp2 = tmp2->next;
    }
	save_head = head;
    while (tmp1 && tmp2)
    {
        if (tmp1->val <= tmp2->val)
        {
            head->next = tmp1;
            tmp1 = tmp1->next;
            head = head->next;
        }
        else
        {
            head->next = tmp2;
            tmp2 = tmp2->next;
            head = head->next;
        }
    }
    if (!tmp1 && tmp2)
        head->next = tmp2;
    else if (!tmp2 && tmp1)
        head->next = tmp1;
    return (save_head);
}

int main(void)
{
	struct ListNode list1a;
	list1a.val = 1;
	struct ListNode list1b;
	list1b.val = 2;
	struct ListNode list1c;
	list1c.val = 4;
	list1a.next = &list1b;
	list1b.next = &list1c;
	list1c.next = NULL;
	struct ListNode *list1 = &list1a;

	struct ListNode list2a;
	list2a.val = 1;
	struct ListNode list2b;
	list2b.val = 3;
	struct ListNode list2c;
	list2c.val = 4;
	list2a.next = &list2b;
	list2b.next = &list2c;
	list2c.next = NULL;
	struct ListNode *list2 = &list2a;

	struct ListNode *list1save = list1;
	struct ListNode *list2save = list2;

	printf("This is list1:\n");
	while(list1 != NULL)
	{
		printf("%i\n", list1->val);
		list1 = list1->next;
	}
	printf("\nThis is list2:\n");
	while(list2 != NULL)
	{
		printf("%i\n", list2->val);
		list2 = list2->next;
	}
	struct ListNode *new = mergeTwoLists(list1save, list2save);
	printf("\nThis is the merged list:\n");
	while(new != NULL)
	{
		printf("%i\n", new->val);
		new = new->next;
	}
}