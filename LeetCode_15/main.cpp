#include "threeSum.h"

int main()
{
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};

    std::vector<std::vector<int>> result = threeSum(nums);

    for (const auto &triplet : result)
    {
        std::cout << "[";
        for (size_t i = 0; i < triplet.size(); ++i)
        {
            std::cout << triplet[i] << (i == triplet.size() - 1 ? "" : ", ");
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}