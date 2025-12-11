#include "four_num_sum.h"

int fourSumCount(std::vector<int> &nums1, std::vector<int> &nums2, std::vector<int> &nums3, std::vector<int> &nums4)
{
    std::unordered_map<int, int> result;
    int count = 0;

    for (int a : nums1)
    {
        for (int b : nums2)
        {
            result[a + b]++;
        }
    }

    for (int c : nums3)
    {
        for (int d : nums4)
        {
            // c + d 算出一个sum值 要让sum + 一个数 = 0 所以我们要再map里找的就是-sum
            int target = -(c + d);
            auto it = result.find(target);
            if (it != result.end())
            {
                count += it->second;
            }
        }
    }
    return count;
}