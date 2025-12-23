#include "Replace_num.h"

std::string replaceNum(std::string s)
{
    int count = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            // 统计数字出现个数
            count++;
        }
    }
    int oldIndex = s.size() - 1;
    // 扩容
    s.resize(s.size() + count * 5);

    int newIndex = s.size() - 1;

    // 替换数字为number
    for (; newIndex >= 0 && oldIndex >= 0; oldIndex--)
    {
        if (s[oldIndex] >= '0' && s[oldIndex] <= '9')
        {
            // 是数字 进行替换
            s[newIndex--] = 'r';
            s[newIndex--] = 'e';
            s[newIndex--] = 'b';
            s[newIndex--] = 'm';
            s[newIndex--] = 'u';
            s[newIndex--] = 'n';
        }
        else
        {
            s[newIndex--] = s[oldIndex];
        }
    }

    return s;
}