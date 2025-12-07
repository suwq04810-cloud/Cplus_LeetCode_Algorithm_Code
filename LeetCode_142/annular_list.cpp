#include "annular_list.h"

ListNode *detectCycle(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;

    // fast每次前进两步 slow前进一步 如果链表有环 那么slow和fast就会相遇
    // 因为fast步长为2 slow步长为1 所以fast相对slow多移动1步 不会出现在环内fast错过slow的情况
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            // 说明有环
            // 开始寻找入环的第一个节点
            ListNode *index1 = fast;
            ListNode *index2 = head;
            while (index1 != index2)
            {
                index1 = index1->next;
                index2 = index2->next;
            }
            return index1;
        }
    }
    return NULL;
}