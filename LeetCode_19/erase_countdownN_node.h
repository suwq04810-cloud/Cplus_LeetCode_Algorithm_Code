#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n);

// 辅助函数 构建链表
ListNode *createList(const std::initializer_list<int> values);

// 打印链表
void printList(ListNode *head);