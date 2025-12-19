#include "reverse_II.h"

int main()
{
    std::string s = "abcdefg";

    std::string ans = reverseStr(s, 2);

    for (auto val : ans)
    {
        std::cout << val << " ";
    }

    return 0;
}