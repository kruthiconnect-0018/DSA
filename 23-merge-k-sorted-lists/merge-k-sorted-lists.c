#include <stdlib.h>

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode* tail = &dummy;

    while (1)
    {
        int smallest = -1;

        // Find the list having the smallest current node
        for (int i = 0; i < listsSize; i++)
        {
            if (lists[i] != NULL)
            {
                if (smallest == -1 ||
                    lists[i]->val < lists[smallest]->val)
                {
                    smallest = i;
                }
            }
        }

        // All lists are empty
        if (smallest == -1)
            break;

        // Add the smallest node to result
        tail->next = lists[smallest];
        tail = tail->next;

        // Move that list forward
        lists[smallest] = lists[smallest]->next;
    }

    return dummy.next;
}