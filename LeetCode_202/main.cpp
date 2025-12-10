#include "happy_number.h"

int main()
{
    int number = 0;
    std::cin >> number;

    bool ans = isHappy(number);

    std::cout << std::boolalpha << ans << std::endl;

    return 0;
}