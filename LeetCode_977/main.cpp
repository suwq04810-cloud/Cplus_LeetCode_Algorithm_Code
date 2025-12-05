#include "order_array_square.h"

int main()
{
    std::vector<int> n = {-3, -2, 0, 5, 6, 9};

    std::vector<int> ans = sortedSquares(n);

    for (const int &element : ans)
    {
        std::cout << element << " ";
    }

    return 0;
}