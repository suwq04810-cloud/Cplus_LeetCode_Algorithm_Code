#include "fourNum.h"

std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
{
    std::vector<std::vector<int>> result;

    // 与三数之和思路相同 先确定两个数 然后用left和right变量后面的数
    sort(nums.begin(), nums.end());

    // 确定a
    for (int i = 0; i < (int)nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < (int)nums.size(); j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }
            int left = j + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                if (static_cast<long>(nums[i]) + nums[j] + nums[left] + nums[right] > target)
                {
                    right--;
                }
                else if (static_cast<long>(nums[i]) + nums[j] + nums[left] + nums[right] < target)
                {
                    left++;
                }
                else
                {
                    // 四数相加为target
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});

                    // 对left和right进行剪枝
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    while (left < right && right > 0 && nums[right] == nums[right - 1])
                    {
                        right--;
                    }

                    right--;
                    left++;
                }
            }
        }
    }
    return result;
}