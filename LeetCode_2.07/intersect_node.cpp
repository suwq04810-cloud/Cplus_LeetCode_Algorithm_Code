#include <utility>
#include "intersect_node.h"

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    // 尾部对齐 如果链表a较长 交点一定再后面 因为前面的a和b是独立的 肯定不会有交点
    // 计算长度差
    ListNode *Acurrent = headA;
    ListNode *Bcurrent = headB;
    int Alen = 0;
    int Blen = 0;

    // 计算链表a的长度
    while (Acurrent)
    {
        Alen++;
        Acurrent = Acurrent->next;
    }
    // 计算链表b的长度
    while (Bcurrent)
    {
        Blen++;
        Bcurrent = Bcurrent->next;
    }
    // 将current更新为头节点 否则指向null
    Acurrent = headA;
    Bcurrent = headB;

    // 比较 消除长度差 从同一起点出发 a长b短
    if (Alen < Blen)
    {
        std::swap(Alen, Blen);
        std::swap(Acurrent, Bcurrent);
    }

    // 尾部对齐
    // 长度差
    int gap = Alen - Blen;
    while (gap--)
    {
        Acurrent = Acurrent->next;
    }

    while (Acurrent)
    {
        if (Acurrent == Bcurrent)
        {
            return Acurrent;
        }
        else
        {
            Acurrent = Acurrent->next;
            Bcurrent = Bcurrent->next;
        }
    }
    return NULL;
}

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
        // 必须放到外部 否则遍历到最后一个节点时 next为空 如果当到内部 就不会更新current的位置 导致死循环
        current = current->next;
    }
}