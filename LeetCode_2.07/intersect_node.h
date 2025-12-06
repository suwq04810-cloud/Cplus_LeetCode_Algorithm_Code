#pragma once // 1. 防止头文件重复包含
#include <iostream>
#include <algorithm>
#include <initializer_list> // 2. 必须包含这个，因为你用了 initializer_list

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

// 辅助函数 创建链表
ListNode *createLinelist(const std::initializer_list<int> &values);

// 辅助函数 打印链表
void printLinklist(const ListNode *head);