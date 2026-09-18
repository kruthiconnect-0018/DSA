/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    // Dummy node
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;

    // Move fast n nodes ahead
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    // Move both pointers
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // Node to delete
    struct ListNode* temp = slow->next;

    // Remove it
    slow->next = slow->next->next;

    // Free memory
    free(temp);

    return dummy.next;
}