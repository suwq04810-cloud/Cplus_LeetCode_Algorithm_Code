#include "reverse_link_list.h"

ListNode *reverseList(ListNode *head)
{
    ListNode *pre = nullptr;
    ListNode *cur = head;

    // 改变cur的指向 记得保存cur->next 否则改变指向后cur无法向后移动
    while (cur)
    {
        ListNode *temp = cur->next;
        cur->next = pre;

        pre = cur;
        cur = temp;
    }

    return pre;
}