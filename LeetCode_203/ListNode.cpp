#include "ListNode.h"

ListNode *removeElements(ListNode *head, int val)
{
    // 使用虚拟头节点
    ListNode *dummnyHead = new ListNode(0);
    dummnyHead->next = head;
    ListNode *current = dummnyHead;

    while (current->next != nullptr)
    {
        if (current->next->val == val)
        {
            ListNode *temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        else
        {
            current = current->next;
        }
    }

    ListNode *result = dummnyHead->next;
    delete dummnyHead;
    return result;
}