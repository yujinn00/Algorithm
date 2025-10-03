#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int num;
    std::cin >> num;

    for (int i = 1; i < num; ++i)
    {
        int tmp = i;
        int sum = i;

        while (tmp != 0)
        {
            sum += tmp % 10;
            tmp /= 10;
        }

        if (sum == num)
        {
            std::cout << i << '\n';
            return 0;
        }
    }

    std::cout << 0 << '\n';

    return 0;
}
