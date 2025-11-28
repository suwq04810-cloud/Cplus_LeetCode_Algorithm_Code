#include "Spiral_Matrix_II.h"

int main()
{
    int n = 0;
    std::cin >> n;

    std::vector<std::vector<int>> ans(n, std::vector<int>(n, 0));
    ans = generateMatrix(n);

    for (const auto& row : ans)
    {
        for (int element : row)
        {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}