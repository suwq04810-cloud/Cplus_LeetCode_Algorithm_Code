#include "reverse_link_list.h"

// 辅助函数 创建链表
ListNode *createLinelist(const std::initializer_list<int> &values)
{
    if (values.size() == 0)
    {
        return nullptr;
    }
    // 虚拟头节点
    ListNode dummy(0);
    ListNode *current = &dummy;

    for (int val : values)
    {
        current->next = new ListNode(val);
        current = current->next;
    }

    return dummy.next;
}

// 辅助函数 打印链表
void printLinklist(const ListNode *head)
{
    const ListNode *current = head;
    while (current != nullptr)
    {
        std::cout << current->val;
        if (current->next != nullptr)
        {
            std::cout << "->";
        }
        current = current->next;
    }
}

int main()
{
    ListNode *head = createLinelist({1, 2, 3, 4, 5});
    ListNode* newHead = reverseList(head);
    printLinklist(newHead);
    return 0;
}