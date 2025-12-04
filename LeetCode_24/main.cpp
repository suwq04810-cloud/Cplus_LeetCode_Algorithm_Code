#include "swap_node.h"

// 辅助函数 创建链表
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
        std::cout << current->val << " ";
        if (current->next != nullptr)
        {
            std::cout << "->";
        }
        current = current->next;
    }
}

int main()
{
    ListNode *head = createList({1, 2, 3, 4, 5, 6});
    ListNode *newHead = swapPairs(head);
    printList(newHead);

    return 0;
}