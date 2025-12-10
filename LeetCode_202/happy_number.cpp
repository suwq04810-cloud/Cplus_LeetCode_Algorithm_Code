#include "happy_number.h"

int getSum(int n)
{
    int sum = 0;

    while (n)
    {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }

    return sum;
}

bool isHappy(int n)
{
    std::unordered_set<int> set;
    while (1)
    {
        // 获取下一次迭代的数据
        int sum = getSum(n);

        // 如果各位和为1 则是快乐数
        if (sum == 1)
        {
            return true;
        }

        // 如果不为1 就在set里查找有无重复的 有重复的则是死循环
        if (set.find(sum) != set.end())
        {
            return false;
        }
        else
        {
            // 不重复 且不为1 进入下一次迭代
            set.insert(sum);
        }
        // 下次迭代的数据
        n = sum;
    }
}