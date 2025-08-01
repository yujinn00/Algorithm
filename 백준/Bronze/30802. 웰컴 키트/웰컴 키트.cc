#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, size[6], t, p;

    std::cin >> n;
    for (int i = 0; i < 6; ++i)
    {
        std::cin >> size[i];
    }
    std::cin >> t >> p;

    int shirts = 0;

    for (int i = 0; i < 6; ++i)
    {
        if (size[i] % t == 0)
        {
            shirts += size[i] / t;
        }
        else
        {
            shirts += (size[i] / t) + 1;
        }
    }

    std::cout << shirts << "\n";
    std::cout << n / p << " " << n % p << "\n";

    return 0;
}
