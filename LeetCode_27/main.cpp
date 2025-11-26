#include "eraseNum.cpp"

int main()
{
    std::vector<int> v = {3, 2, 2, 3};
    int ans = removeElement(v, 3);
    std::cout << ans << std::endl;

    return 0;
}