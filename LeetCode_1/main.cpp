#include "twoNum.h"

int main()
{
    std::vector<int> vec = {1, 3, 5, 2, 6, 7};
    int target = 9;
    std::vector<int> ans = twoSum(vec, target);

    for (int val : ans)
    {
        std::cout << val << " ";
    }

    return 0;
}