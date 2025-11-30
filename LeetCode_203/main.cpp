#include "ListNode.h"

// 辅助函数：打印链表
void printList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        std::cout << current->val << (current->next ? " -> " : "");
        current = current->next;
    }
    std::cout << std::endl;
}

int main()
{
    ListNode *n4 = new ListNode(4);
    ListNode *n6_2 = new ListNode(6, n4);
    ListNode *n3 = new ListNode(3, n6_2);
    ListNode *n6_1 = new ListNode(6, n3);
    ListNode *n2 = new ListNode(2, n6_1);
    ListNode *head = new ListNode(1, n2);

    int remove_element = 3;

    ListNode *newhead = removeElements(head, remove_element);
    printList(newhead);

    return 0;
}