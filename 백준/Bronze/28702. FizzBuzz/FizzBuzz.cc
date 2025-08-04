#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;

    int num = 0;

    if (s1[2] != 'z')
    {
        num = atoi(s1.c_str()) + 3;
    }
    if (s2[2] != 'z')
    {
        num = atoi(s2.c_str()) + 2;
    }
    if (s3[2] != 'z')
    {
        num = atoi(s3.c_str()) + 1;
    }

    if (num % 3 == 0 && num % 5 == 0)
    {
        std::cout << "FizzBuzz\n";
    }
    else if (num % 3 == 0 && num % 5 != 0)
    {
        std::cout << "Fizz\n";
    }
    else if (num % 3 != 0 && num % 5 == 0)
    {
        std::cout << "Buzz\n";
    }
    else
    {
        std::cout << num << "\n";
    }

    return 0;
}
