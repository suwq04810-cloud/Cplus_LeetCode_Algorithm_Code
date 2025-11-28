#include "MinLength_SubArray.h"

int main()
{
    std::vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    int target1 = 7;
    std::cout << "Test 1: " << minSubArrayLen(target1, nums1) << std::endl; // 2

    std::vector<int> nums2 = {1, 4, 4};
    int target2 = 4;
    std::cout << "Test 2: " << minSubArrayLen(target2, nums2) << std::endl; // 1

    std::vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    int target3 = 11;
    std::cout << "Test 3: " << minSubArrayLen(target3, nums3) << std::endl; // 0

    return 0;
}
