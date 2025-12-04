#include "swap_node.h"

ListNode *swapPairs(ListNode *head)
{
    ListNode dummy(0);
    dummy.next = head;
    ListNode *current = &dummy;

    while (current->next != nullptr && current->next->next != nullptr)
    {
        ListNode *temp = current->next;
        ListNode *temp2 = temp->next->next;

        current->next = temp->next;
        temp->next->next = temp;
        temp->next = temp2;

        current = current->next->next;
    }
    ListNode *ans = dummy.next;
    return ans;
}