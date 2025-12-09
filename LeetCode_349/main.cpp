#include "array_intersection.h"

int main()
{
    std::vector<int> nums1 = {1, 2, 2, 1};
    std::vector<int> nums2 = {2, 2};

    std::vector<int> ans = intersection(nums1, nums2);

    for (int val : ans)
    {
        std::cout << val << std::endl;
    }

    return 0;
}