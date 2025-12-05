#include "erase_countdownN_node.h"

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // 找到倒数第n个节点的前一个节点pre
    // 使用双指针
    ListNode dummy(0);
    dummy.next = head;
    ListNode *slow = &dummy;
    ListNode *fast = &dummy;

    // 让fast先走n + 1步
    int count = n + 1;

    while (count--)
    {
        fast = fast->next;
    }

    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    // 跳出循环 说明找到了倒数第n个节点的前一个节点 就是slow指向的位置
    ListNode *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return dummy.next;
}

// 辅助函数 构建链表
ListNode *createList(const std::initializer_list<int> values)
{
    if (values.size() == 0)
    {
        return nullptr;
    }

    ListNode dummy(0);
    ListNode *current = &dummy;

    for (int val : values)
    {
        current->next = new ListNode(val);
        current = current->next;
    }

    return dummy.next;
}

// 打印链表
void printList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        std::cout << current->val;
        if (current->next != nullptr)
        {
            std::cout << "->";
        }
        // 必须放到外部 否则遍历到最后一个节点时 next为空 如果当到内部 就不会更新current的位置 导致死循环
        current = current->next;
    }
}