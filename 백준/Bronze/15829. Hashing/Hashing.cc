#include <iostream>
#include <string>

const int r = 31;
const int M = 1234567891;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int l;
    std::cin >> l;
    
    std::string str;
    std::cin >> str;
    
    long long hash = 0;
    long long pow = 1;
    for (int i = 0; i < l; ++i)
    {
        int tmp = str[i] - 'a' + 1;
        hash = (hash + tmp * pow) % M;
        pow = (pow * r) % M;
    }

    std::cout << hash << "\n";

    return 0;
}
