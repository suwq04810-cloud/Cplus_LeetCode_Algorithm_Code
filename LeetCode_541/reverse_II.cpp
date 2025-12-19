#include "reverse_II.h"

std::string reverseStr(std::string s, int k)
{
    for (int i = 0; i < (int)s.size(); i += (2 * k))
    {
        // 从i开始 +k个字符 如果还在数组范围内 则反转前k个字符
        if (i + k <= (int)s.size())
        {
            reverse(s.begin() + i, s.begin() + i + k);
            continue;
        }
        // 如果从i开始到字符串结束 不够k个 则从i开始全部反转
        reverse(s.begin() + i, s.end());
    }
    return s;
}