#include "threeSum.h"

std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    std::vector<std::vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < (int)nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            return result;
        }
        int left = i + 1;
        int right = nums.size() - 1;

        // 对 a 进行去重
        // 例如 nums = (-1 -1 0 0 1 1) 如果不去重a 那么收获的结果将会是两个(-1 0 1) 不符合题目要求的不重复的三元组
        // 这里必须使用nums[i]和nums[i - 1] 如果使用nums[i]和nums[i + 1]判断 i + 1存放的是left 相当于判断了三元组内不能有重复元素
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        // 开始移动left 和 right指针
        // left 不能等于 right 当left和right相等时 指向同一个元素 因为三元组内元素的下标不能重复
        while (left < right)
        {
            if (nums[i] + nums[left] + nums[right] > 0)
            {
                right--;
            }
            else if (nums[i] + nums[left] + nums[right] < 0)
            {
                left++;
            }
            else
            {
                result.push_back({nums[i], nums[left], nums[right]});
                // 对b和c进行去重 比如 -1 0 0 0 0 1 1 1 1 收获了一个符合条件的三元组(-1 0 1) 要对left和right指向的0 1去重
                while (left < right && nums[left] == nums[left + 1])
                {
                    left++;
                }
                while (left < right && right > 0 && nums[right] == nums[right - 1])
                {
                    right--;
                }
                // 当b和c去重过后 例如 -2 0 0 0 1 1 1 2 2 2
                // 去重过后 left指向下标为3的0 right指向下标为7的2上 然后要移动left和right 使他们指向新的元素
                left++;
                right--;
            }
        }
    }
    return result;
}