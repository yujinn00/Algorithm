#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num, sum = 0;

    for (int i = 0; i < 5; ++i)
    {
        std::cin >> num;
        sum += num * num;
    }

    std::cout << sum % 10 << "\n";

    return 0;
}
