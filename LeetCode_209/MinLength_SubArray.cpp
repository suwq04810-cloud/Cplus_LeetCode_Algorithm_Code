#include "MinLength_SubArray.h"
#include <climits>

// 滑动窗口解法
int minSubArrayLen(int target, std::vector<int> &nums)
{
    // 滑动窗口
    int sum = 0;
    int length = 0;
    int result = INT_MAX;
    int left = 0;

    // right表示滑动窗口终止位置
    for (size_t right = 0; right < nums.size(); right++)
    {

        sum += nums[right];
        while (sum >= target)
        {
            length = right - left + 1;

            result = length < result ? length : result;

            // 更新起始位置
            sum -= nums[left++];
            // left++;
        }
    }
    return result == INT_MAX ? 0 : result;
}

/*
int minSubArrayLen(int target, std::vector<int> &nums)
{
    // 暴力解法 两层for循环遍历
    // 最终的返回结果 子序列长度
    int result = INT_MAX;
    // 区间和
    int sum = 0;
    // 计算不同起点sum >= target的区间长度
    int length = 0;
    for (int left = 0; left < nums.size(); left++)
    {
        sum = 0;
        for (int right = left; right < nums.size(); right++)
        {
            // 从left开始 一直向后移动right 并把对应值加到sum上
            sum += nums[right];
            if (sum >= target)
            {
                length = right - left + 1;

                // 更新result 并比较每次以不同起点得到的最小子数组 取长度最小的
                result = result < length ? result : length;
                // 因为数组内都是正整数 所以第一次找到的子序列 一定是以left为起始点的最小子序列
                break;
            }
        }
    }

    return result == INT_MAX ? 0 : result;
}
*/