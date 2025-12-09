#include "array_intersection.h"

std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2)
{
    // unset 来存放结果 用来去重
    std::unordered_set<int> result;
    // 存放去重后的nums1 与 nums2 比较
    std::unordered_set<int> member(nums1.begin(), nums1.end());

    for (int num : nums2)
    {
        if (member.find(num) != member.end())
        {
            result.insert(num);
        }
    }

    return std::vector<int>(result.begin(), result.end());
}