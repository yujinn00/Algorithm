#include <iostream>
#include <cmath>

static bool Prime(long long num)
{
    if (num == 0 || num == 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i <= sqrt(num); i += 2)
    {
        if (num % i == 0) return false;
    }

    return true;
}

int main()
{
    int n;

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        long long m;

        std::cin >> m;

        while (!Prime(m))
        {
            m++;
        }

        std::cout << m << "\n";
    }

    return 0;
}