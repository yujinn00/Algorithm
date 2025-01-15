#include <iostream>
#include <vector>
#include <cmath>

std::vector<bool> prime(1000001, true);

static void Prime()
{
    prime[0] = prime[1] = false;

    for (int i = 2; i < sqrt(prime.size()); ++i)
    {
        if (prime[i])
        {
            for (int j = i * i; j < prime.size(); j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int main()
{
    int t;
    std::cin >> t;

    Prime();

    while (t--)
    {
        int n, count = 0;
        std::cin >> n;

        for (int i = 2; i <= n / 2; ++i)
        {
            if (prime[i] && prime[n - i])
            {
                ++count;
            }
        }

        std::cout << count << "\n";
    }
}