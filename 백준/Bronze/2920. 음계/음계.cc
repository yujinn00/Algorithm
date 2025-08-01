#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int scale[8], asc = 0, desc = 0;

    for (int i = 0; i < 8; ++i)
    {
        std::cin >> scale[i];

        if (scale[i] == i + 1)
        {
            asc++;
        }
        else if (scale[i] == 8 - i)
        {
            desc++;
        }
    }

    if (asc == 8)
    {
        std::cout << "ascending\n";
    }
    else if (desc == 8)
    {
        std::cout << "descending\n";
    }
    else
    {
        std::cout << "mixed\n";
    }

    return 0;
}
