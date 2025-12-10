#include "twoNum.h"

// unordered_map
std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::unordered_map<int, int> map;

    for (int i = 0; i < (int)nums.size(); i++)
    {
        int each_num = target - nums[i];

        if (map.find(each_num) != map.end())
        {
            return {map.find(each_num)->second, i};
        }

        map.insert(std::pair<int, int>(nums[i], i));
    }
    return {};
}

// std::vector<int> twoSum(std::vector<int> &nums, int target)
// {
//     int sum = 0;
//     for (int i = 0; i < (int)nums.size(); i++)
//     {
//         for (int j = i + 1; j < nums.size(); j++)
//         {
//             if (nums[i] + nums[j] == target)
//             {
//                 return {i, j};
//             }
//         }
//     }

//     return {};
// }