#include <iostream>

// 链表节点结构体定义
struct ListNode
{
    int val;
    ListNode *next;

    // 构造函数
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeElements(ListNode *head, int val);