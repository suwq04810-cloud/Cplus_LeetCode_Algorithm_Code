#include "intersect_node.h"

int main()
{
    // 1. 构造公共部分 (例如: 8 -> 4 -> 5)
    // 这是两个链表真正重合的部分
    ListNode *common = createLinelist({8, 4, 5});

    // 2. 构造 A 的独立部分 (例如: 4 -> 1)
    ListNode *headA = createLinelist({4, 1});

    // 3. 构造 B 的独立部分 (例如: 5 -> 0 -> 1)
    ListNode *headB = createLinelist({5, 0, 1});

    // 4. 关键步骤：手动拼接，制造相交！
    // 找到 A 的最后一个节点
    ListNode *tempA = headA;
    while (tempA->next != nullptr)
    {
        tempA = tempA->next;
    }
    // 让 A 的尾巴指向公共部分
    tempA->next = common;

    // 找到 B 的最后一个节点
    ListNode *tempB = headB;
    while (tempB->next != nullptr)
    {
        tempB = tempB->next;
    }
    // 让 B 的尾巴指向公共部分
    tempB->next = common;

    /*
     现在的结构：
           A: 4 -> 1↘
                      8 -> 4 -> 5
     B: 5 -> 0 -> 1 ↗
    */

    // 5. 调用你的算法
    ListNode *intersection = getIntersectionNode(headA, headB);

    // 6. 打印结果
    if (intersection != nullptr)
    {
        std::cout << "找到交点，交点值为: " << intersection->val << std::endl;
        // 验证一下地址是否相同 (可选)
        std::cout << "交点地址: " << intersection << std::endl;
        std::cout << "Common地址: " << common << std::endl;
    }
    else
    {
        std::cout << "未找到交点 (错误)" << std::endl;
    }

    return 0;
}