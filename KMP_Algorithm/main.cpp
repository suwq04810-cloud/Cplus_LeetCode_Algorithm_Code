#include "KMP.h"

int main()
{
    std::string str = "abcxabcdabcxdabcy";
    std::string subString = "cdabcx";

    int ret = KMP(str, subString);

    std::cout << ret;

    return 0;
}