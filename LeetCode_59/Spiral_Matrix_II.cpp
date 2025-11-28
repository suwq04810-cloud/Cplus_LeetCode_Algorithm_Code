#include "Spiral_Matrix_II.h"

std::vector<std::vector<int>> generateMatrix(int n)
{
    std::vector<std::vector<int>> ret(n, std::vector<int>(n, 0));
    // 起始位置坐标
    int startx = 0;
    int starty = 0;
    // 转圈数
    int loop = n / 2;
    // n为奇数时 处理中间位置的值 例如 n = 3 mid = 1 中间值就是(1, 1)
    int mid = n / 2;
    // 为每个空格赋值
    int count = 1;
    // 每一条边遍历的长度
    int length = 1;

    int i = 0;
    int j = 0;

    while (loop--)
    {
        i = startx;
        j = starty;

        // 左闭右开
        // 上边的边 左->右
        for (; j < n - length; j++)
        {
            // 后置++ 先使用count的值 在进行++操作
            ret[i][j] = count++;
        }

        // 右边的边 上->下
        for (; i < n - length; i++)
        {
            ret[i][j] = count++;
        }

        // 左开右闭
        // 下边的边 右->左
        for (; j >= length; j--)
        {
            ret[i][j] = count++;
        }

        // 左边的边 下->上
        for (; i >= length; i--)
        {
            ret[i][j] = count++;
        }

        // 转完外围后 更新起始位置和每条边要遍历得长度
        startx++;
        starty++;
        length += 1;
    }

    // 判断n的奇偶
    if (n % 2 != 0)
    {
        ret[mid][mid] = count;
    }

    return ret;
}