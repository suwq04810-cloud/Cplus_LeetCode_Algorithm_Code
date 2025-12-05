#include "erase_countdownN_node.h"


int main()
{
    ListNode *ans = createList({1, 2, 3, 4, 5});
    ListNode *newHead = removeNthFromEnd(ans, 2);
    printList(newHead);

    return 0;
}