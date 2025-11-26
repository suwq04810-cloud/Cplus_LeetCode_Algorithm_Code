#include "Two_point_search.h"

// 左闭右闭
/*
int search(std::vector<int> &nums, int target)
{
    // 定义左右区间起始位置
    int left = 0;
    int right = nums.size() - 1;

    // 根据 左闭右闭 区间来比较
    while (left <= right)
    {
        // 计算中间值 并防止溢出
        int middle = left + (right - left) / 2;

        // 说明target在左边
        if (target < nums[middle])
        {
            right = middle - 1;
        }
        // target在右边
        else if (target > nums[middle])
        {
            left = middle + 1;
        }
        // 找到了 直接返回
        else
        {
            return middle;
        }
    }
    // 没有找到 返回-1
    return -1;
}
*/

int search(std::vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size();

    while (left < right)
    {
        int middle = left + (right - left) / 2;

        if (target < nums[middle])
        {
            // 更新右区间
            right = middle;
        }
        else if (target > nums[middle])
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }
    }

    return left;
}