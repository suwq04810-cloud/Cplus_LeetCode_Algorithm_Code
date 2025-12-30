#include "KMP.h"

// 构建 LPS (Longest Prefix Suffix) 数组
std::vector<int> computeLPSArray(const std::string &pattern)
{
    int n = pattern.length();
    std::vector<int> lps(n, 0);
    int index = 0; // 指向前缀待比较的位置 视频中j的位置

    for (int i = 1; i < n;)
    {
        // 可以匹配
        if (pattern[i] == pattern[index])
        {
            lps[i] = index + 1;
            i++;
            index++;
        }
        else
        {
            if (index != 0)
            {
                // 如果不匹配 index的下一个点的位置就是lps数组中前一个字符的值
                index = lps[index - 1];
                i++;
            }
            else
            {
                index = 0;
                i++;
            }
        }
    }

    return lps;
}

int KMP(const std::string text, const std::string pattern)
{
    if (pattern.empty())
    {
        return 0;
    }

    std::vector<int> lps = computeLPSArray(pattern);

    int i = 0; // 文本串指针
    int j = 0; // 模式串指针

    while (i < (int)text.length() && j < (int)pattern.length())
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    if (j == (int)pattern.length())
    {
        return i - pattern.length();
    }
    else
    {
        return -1;
    }
}