#include "fourNum.h"

int main()
{
    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    std::vector<std::vector<int>> ans = fourSum(nums, target);

    for (auto ret : ans)
    {
        std::cout << "[";
        for (int val : ret)
        {
            std::cout << val << " ";
        }
        std::cout << "] ";
    }

    return 0;
}