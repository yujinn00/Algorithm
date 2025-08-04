#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string isbn;
    std::cin >> isbn;

    int sum = 0;
    bool IsOdd = false;
    for (int i = 0; i < isbn.length(); ++i)
    {
        if (isbn[i] != '*')
        {
            if (i % 2 == 0)
            {
                sum += isbn[i] - '0';
            }
            else
            {
                sum += (isbn[i] - '0') * 3;
            }
        }
        else
        {
            if (i % 2 == 0)
            {
                IsOdd = true;
            }
        }
    }

    if (IsOdd)
    {
        for (int i = 1; i <= 9; ++i)
        {
            if ((sum + i) % 10 == 0)
            {
                std::cout << i << "\n";
            }
        }
    }
    else
    {
        for (int i = 0; i <= 9; ++i)
        {
            if ((sum + 3 * i) % 10 == 0)
            {
                std::cout << i << "\n";
            }
        }
    }

    return 0;
}
