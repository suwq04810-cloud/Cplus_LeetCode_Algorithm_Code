#include "annular_list.h"

// 辅助函数：创建链表并形成环
ListNode *createListWithCycle(int length, int pos)
{
    if (length == 0)
        return NULL;

    // 创建节点
    ListNode *head = new ListNode(1);
    ListNode *current = head;
    ListNode *cycle_start = NULL; // 用于标记环的入口点

    for (int i = 2; i <= length; ++i)
    {
        current->next = new ListNode(i);
        current = current->next;
        if (i == pos + 1)
        { // 链表索引从0开始 节点值从1开始 所以 pos+1 是环的入口节点值
            cycle_start = current;
        }
    }

    // 形成环：将链表尾部连接到 cycle_start
    if (pos >= 0 && cycle_start != NULL)
    {
        // 上面循环结束后 current指向末尾节点 让末尾节点指向环开始节点 即可成环
        current->next = cycle_start;
        std::cout << "Successfully created a linked list of length " << length
                  << " with a cycle starting at node " << cycle_start->val << ".\n";
    }
    else
    {
        std::cout << "Successfully created a straight linked list of length " << length << ".\n";
    }

    return head;
}

// 辅助函数：清理内存 (对于无环链表)
void deleteList(ListNode *head)
{
    ListNode *current = head;
    while (current != NULL)
    {
        ListNode *next = current->next;
        delete current;
        current = next;
    }
}

int main()
{
    // --- 测试案例 1: 有环 ---
    // 链表: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (环入口)
    // 长度: 5, pos = 2 (节点值为 3)
    ListNode *list1 = createListWithCycle(5, 2);
    ListNode *cycle_node1 = detectCycle(list1);

    std::cout << "Test Case 1 (Cycle at 3): ";
    if (cycle_node1 != NULL)
    {
        std::cout << "Cycle detected. The entry node value is: " << cycle_node1->val << " (Expected: 3)\n";
    }
    else
    {
        std::cout << "No cycle detected. (Error)\n";
    }

    // --- 测试案例 2: 无环 ---
    // 链表: 1 -> 2 -> 3 -> NULL
    // 长度: 3, pos = -1 (无环)
    ListNode *list2 = createListWithCycle(3, -1);
    ListNode *cycle_node2 = detectCycle(list2);

    std::cout << "Test Case 2 (No Cycle): ";
    if (cycle_node2 == NULL)
    {
        std::cout << "No cycle detected. (Expected: NULL)\n";
    }
    else
    {
        std::cout << "Cycle detected at " << cycle_node2->val << ". (Error)\n";
    }
    // 清理无环链表的内存
    deleteList(list2);

    // --- 测试案例 3: 环在头部 ---
    // 链表: 1 -> 2 -> 1 (环入口)
    // 长度: 2, pos = 0 (节点值为 1)
    ListNode *list3 = createListWithCycle(2, 0);
    ListNode *cycle_node3 = detectCycle(list3);

    std::cout << "Test Case 3 (Cycle at 1): ";
    if (cycle_node3 != NULL)
    {
        std::cout << "Cycle detected. The entry node value is: " << cycle_node3->val << " (Expected: 1)\n";
    }
    else
    {
        std::cout << "No cycle detected. (Error)\n";
    }
}