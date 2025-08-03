#include <iostream>
#include <string>

bool IsPalin(std::string word)
{
    for (int i = 0; i < word.length(); ++i)
    {
        if (word[i] != word[word.length() - i - 1])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string word;
    while (std::cin >> word)
    {
        if (word == "0")
        {
            break;
        }

        if (IsPalin(word))
        {
            std::cout << "yes\n";
        }
        else
        {
            std::cout << "no\n";
        }
    }

    return 0;
}
