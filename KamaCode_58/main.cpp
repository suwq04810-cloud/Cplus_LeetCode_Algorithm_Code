#include <iostream>
#include <vector>

// 卡码网 58 区间和
// 前缀和
int main()
{
    int n = 0;
    std::cin >> n;

    std::vector<int> p(n);
    std::vector<int> arr(n);
    // 计算每个前n项和
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];

        sum += arr[i];

        p[i] += sum;
    }

    int a = 0;
    int b = 0;
    while (std::cin >> a >> b)
    {
        int ret = 0;
        if (a == 0)
        {
            ret = p[b];
        }
        else
        {
            ret = p[b] - p[a - 1];
        }

        std::cout << ret << std::endl;
    }

    return 0;
}

// 暴力求解
/*
int main()
{
    int n = 0;
    std::cin >> n;

    std::vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> ans[i];
    }

    int a = 0;
    int b = 0;
    while (std::cin >> a >> b)
    {
        int sum = 0;

        for (int i = a; i <= b; i++)
        {
            sum += ans[i];
        }

        std::cout << sum << std::endl;
    }

    return 0;
}
*/