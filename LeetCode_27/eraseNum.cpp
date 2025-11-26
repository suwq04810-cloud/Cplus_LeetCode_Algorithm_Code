#include "eraseNum.h"

// 双指针
int removeElement(std::vector<int> &nums, int val)
{
    // slow指向新数组的下标
    int slow = 0;
    // fast寻找新数组的元素
    size_t fast = 0;

    for (fast = 0; fast < nums.size(); fast++)
    {
        // 如果fast指向的值不为val 就把对应的值赋给nums[slow]
        if (nums[fast] != val)
        {
            nums[slow++] = nums[fast];
        }
    }

    return slow;
}

// 暴力解
int removeElement(std::vector<int> &nums, int val)
{
    int size = nums.size();

    for (int i = 0; i < size; i++)
    {
        if (nums[i] == val)
        {
            // 让后面的数据覆盖
            for (int j = i + 1; j < size; j++)
            {
                nums[j - 1] = nums[j];
            }
            i--;
            size--;
        }
    }

    return size;
}